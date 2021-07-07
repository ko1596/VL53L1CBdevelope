/**
******************************************************************************
* File Name          : main.c
* Description        : Main program body
******************************************************************************
*
* COPYRIGHT(c) 2020 STMicroelectronics
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of STMicroelectronics nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include "stm32xxx_hal.h"

/* USER CODE BEGIN Includes */
#include "main.h"
#include "vl53l1_api.h"
#include "53L1A2.h"
/* USER CODE END Includes */
/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart2;
VL53L1_Dev_t                   dev;
VL53L1_DEV                     Dev = &dev;
int status;
volatile int IntCount;
#define isInterrupt 0 /* If isInterrupt = 1 then device working in interrupt mode, else device working in polling mode */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
void RangingLoop(void); /* */
void SingleRangingLoop(void);
void Multizones(void);
void SingleRoi(void);
void TestApi(void);

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 0xFFFF);
  return ch;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin==VL53L1X_INT_Pin)
  {
    IntCount++;
  }
}

/* USER CODE END 0 */

int main(void)
{
  /* USER CODE BEGIN 1 */
  
  uint8_t byteData;
  uint16_t wordData;
  uint8_t ToFSensor = 1; // 0=Left, 1=Center(default), 2=Right
  
  /* MCU Configuration----------------------------------------------------------*/
  
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  
  /* Configure the system clock */
  SystemClock_Config();
  
  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  
  MX_USART2_UART_Init();
  
  MX_I2C1_Init();
  
  XNUCLEO53L1A1_Init();
  
  /* USER CODE END 1 */
  
  /* USER CODE BEGIN 2 */
  
  printf("VL53L1X Examples...\n");
  Dev->I2cHandle = &hi2c1;
  Dev->I2cDevAddr = 0x52;
  
  /* Allow to select the sensor to be used, multi-sensor is not managed in this example.
  Only when use use the Left ToF in interrupt mode,  solder the U7 on the X-Nucleo-53L1A1 board 
  Only when use the Right ToF in interrupt mode, solder the U7 on the X-Nucleo-53L1A1 board
  See "Solder drop configurations" in the X-Nucleo-53L1A1 User Manual for more details */
  ToFSensor = 1; // Select ToFSensor: 0=Left, 1=Center, 2=Right
  status = XNUCLEO53L1A1_ResetId(ToFSensor, 0); // Reset ToF sensor
  HAL_Delay(2);
  status = XNUCLEO53L1A1_ResetId(ToFSensor, 1); // Reset ToF sensor
  HAL_Delay(2);
  
  VL53L1_RdByte(Dev, 0x010F, &byteData);
  printf("VL53L1X Model_ID: %02X\n\r", byteData);
  VL53L1_RdByte(Dev, 0x0110, &byteData);
  printf("VL53L1X Module_Type: %02X\n\r", byteData);
  VL53L1_RdWord(Dev, 0x010F, &wordData);
  printf("VL53L1X: %02X\n\r", wordData);
//  RangingLoop();
//  SingleRangingLoop();
  Multizones();
  //SingleRoi();
  //TestApi();
  /* USER CODE END 2 */
  
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    
    /* USER CODE BEGIN 3 */
    
  }
  /* USER CODE END 3 */
  
}

/** System Clock Configuration
*/
#ifdef STM32F401xE

void SystemClock_Config(void)
{
  
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  
  /**Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
    |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure the Systick interrupt time 
  */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
  
  /**Configure the Systick 
  */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
  
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}
#endif

#ifdef STM32L476xx
void SystemClock_Config(void)
{
  
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;
  
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
    |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure the Systick interrupt time 
  */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
  
  /**Configure the Systick 
  */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
  
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}
#endif
#ifdef STM32F401xE

/* I2C1 init function */
static void MX_I2C1_Init(void)
{
  
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  
}
#endif
#ifdef STM32L476xx
/* I2C1 init function */
static void MX_I2C1_Init(void)
{
  
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x10909CEC;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure Analogue filter 
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure Digital filter 
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  
}
#endif
/* USART2 init function */
static void MX_USART2_UART_Init(void)
{
  
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  
}

/** Configure pins as 
* Analog 
* Input 
* Output
* EVENT_OUT
* EXTI
*/
static void MX_GPIO_Init(void)
{
  
  GPIO_InitTypeDef GPIO_InitStruct;
  
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
  
  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);
  
  /*Configure GPIO pin : VL53L1X_INT_Pin */
  GPIO_InitStruct.Pin = VL53L1X_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(VL53L1X_INT_GPIO_Port, &GPIO_InitStruct);
  
  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);
  
  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);
  
}
/* USER CODE BEGIN 4 */
/* Ranging loop*/
void RangingLoop(void)
{
  VL53L1_MultiRangingData_t MultiRangingData;
  VL53L1_MultiRangingData_t *pMultiRangingData = &MultiRangingData;
  uint8_t NewDataReady = 0;
  int no_of_object_found = 0, j;
  printf("Ranging loop starts\n");
  status = VL53L1_WaitDeviceBooted(Dev);
  status = VL53L1_DataInit(Dev);
  status = VL53L1_StaticInit(Dev);
  /* VL53L1_SetPresetMode function is mandatory to be called even if default PresetMode is the VL53L1_PRESETMODE_RANGING */
  status = VL53L1_SetPresetMode(Dev, VL53L1_PRESETMODE_RANGING);		//更改模式
  //status = VL53L1_SetDistanceMode(Dev, VL53L1_DISTANCEMODE_SHORT);		//偵測強度
  //status = VL53L1_SetMeasurementTimingBudgetMicroSeconds(Dev, 60000);
  status = VL53L1_StartMeasurement(Dev);
  if(status){
    printf("VL53L1_StartMeasurement failed: error = %d \n", status);
    while(1);
  }
  if (isInterrupt){
    do // HW interrupt mode
    {
      __WFI();
      if(IntCount !=0 ){
        IntCount=0;
        status = VL53L1_GetMultiRangingData(Dev, pMultiRangingData);
        no_of_object_found=pMultiRangingData->NumberOfObjectsFound;
        printf("Count=%5d, ", pMultiRangingData->StreamCount);
        printf("#Objs=%1d ", no_of_object_found);
        for(j=0;j<no_of_object_found;j++){
          if(j!=0)printf("\n                     \r");
          printf("status=%d, D=%5dmm, Signal=%2.2f Mcps, Ambient=%2.2f Mcps(interrupt mode)",
                 pMultiRangingData->RangeData[j].RangeStatus,
                 pMultiRangingData->RangeData[j].RangeMilliMeter,
                 pMultiRangingData->RangeData[j].SignalRateRtnMegaCps/65536.0,
                 pMultiRangingData->RangeData[j].AmbientRateRtnMegaCps/65536.0);
        }
        printf ("\n\r");
        if (status==0){
          status = VL53L1_ClearInterruptAndStartMeasurement(Dev);
        }
      }
    }
    while(1);
  }
  else{
    do{ // polling mode
      status = VL53L1_GetMeasurementDataReady(Dev, &NewDataReady);
      HAL_Delay(1);
      if((!status)&&(NewDataReady!=0)){
        status = VL53L1_GetMultiRangingData(Dev, pMultiRangingData);
        no_of_object_found=pMultiRangingData->NumberOfObjectsFound;
        printf("Count=%5d, ", pMultiRangingData->StreamCount);
        printf("#Objs=%1d ", no_of_object_found);
        for(j=0;j<no_of_object_found;j++){
          if(j!=0)printf("\n                     \r");
          printf("status=%d, D=%5dmm, Signal=%2.2f Mcps, Ambient=%2.2f Mcps(polling mode)",
                 pMultiRangingData->RangeData[j].RangeStatus,
                 pMultiRangingData->RangeData[j].RangeMilliMeter,
                 pMultiRangingData->RangeData[j].SignalRateRtnMegaCps/65536.0,
                 pMultiRangingData->RangeData[j].AmbientRateRtnMegaCps/65536.0);
        }
        printf ("\n\r");
        if (status==0){
          status = VL53L1_ClearInterruptAndStartMeasurement(Dev);
        }
      }
    }
    while (1);
  }
}

void SingleRangingLoop(void)
{
	VL53L1_RangingMeasurementData_t RangingMeasurementData;
	VL53L1_RangingMeasurementData_t *pRangingMeasurementData = &RangingMeasurementData;
	uint8_t NewDataReady = 0;
	printf("Ranging loop starts\n");
	status = VL53L1_WaitDeviceBooted(Dev);
	status = VL53L1_DataInit(Dev);
	status = VL53L1_StaticInit(Dev);
	/* VL53L1_SetPresetMode function is mandatory to be called even if default PresetMode is the VL53L1_PRESETMODE_RANGING */
	status = VL53L1_SetPresetMode(Dev, VL53L1_PRESETMODE_RANGING);		//更改模式
	status = VL53L1_SetDistanceMode(Dev, VL53L1_DISTANCEMODE_LONG);		//偵測強度
	//status = VL53L1_SetMeasurementTimingBudgetMicroSeconds(Dev, 60000);
	status = VL53L1_StartMeasurement(Dev);

	if(status){
	  printf("VL53L1_StartMeasurement failed: error = %d \n", status);
	  while(1);
	}

	do{ // polling mode
	    status = VL53L1_GetMeasurementDataReady(Dev, &NewDataReady);
	    HAL_Delay(1);
	    if((!status)&&(NewDataReady!=0)){
	      status = VL53L1_GetRangingMeasurementData(Dev, pRangingMeasurementData);
	      printf("Count=%5d, ", pRangingMeasurementData->StreamCount);

	      printf("status=%d, D=%5dmm, Signal=%2.2f Mcps, Ambient=%2.2f Mcps(polling mode)",
	    		  pRangingMeasurementData->RangeStatus,
				  pRangingMeasurementData->RangeMilliMeter,
				  pRangingMeasurementData->SignalRateRtnMegaCps/65536.0,
				  pRangingMeasurementData->AmbientRateRtnMegaCps/65536.0);

	      printf ("\n\r");
	      if (status==0){
	        status = VL53L1_ClearInterruptAndStartMeasurement(Dev);
	      }
	    }
	  }
	  while (1);
}

/* Multizones loop*/
void Multizones(void)
{
  VL53L1_MultiRangingData_t MultiRangingData;
  VL53L1_MultiRangingData_t *pMultiRangingData = &MultiRangingData;
  uint8_t NewDataReady = 0;
  uint8_t NumROI = 16, RoiNumber=0, RoiStatus=0;
  int no_of_object_found = 0, j, k;
  VL53L1_RoiConfig_t pRoiConfig;
  printf("Multizones loop starts\n");
  status = VL53L1_WaitDeviceBooted(Dev);
  status = VL53L1_DataInit(Dev);
  status = VL53L1_StaticInit(Dev);
  /*VL53L1_SetPresetMode function is mandatory to be called even if default PresetMode is the VL53L1_PRESETMODE_RANGING */
  status = VL53L1_SetPresetMode(Dev, VL53L1_PRESETMODE_MULTIZONES_SCANNING);
  pRoiConfig.NumberOfRoi=NumROI;
  
  printf("Start set Roi");
  for(k=0;k<4;k++)
	  for(j=0;j<4;j++)
	  {
		  pRoiConfig.UserRois[k*4+j].TopLeftX=j*4;
		  pRoiConfig.UserRois[k*4+j].TopLeftY=k*4+3;
		  pRoiConfig.UserRois[k*4+j].BotRightX=j*4+3;
		  pRoiConfig.UserRois[k*4+j].BotRightY=k*4;
		  printf("set Roi %d\n\rx: %d-%d    y: %d-%d\n\r",k*4+j,j*4,j*4+3,k*4,k*4+3);
	  }


  /* VL53L1_SetROI must be called after VL53L1_SetPresetMode */
  status = VL53L1_SetROI(Dev, &pRoiConfig);
  if (!status){
    status = VL53L1_StartMeasurement(Dev);
  }
  else{
    printf("VL53L1_SetROI failed: error =%d\n\r", status);
    while(1){};
  };
  if(status){
    printf("VL53L1_StartMeasurement failed: error = %d \n\r", status);
    while(1);
  }
  if (isInterrupt){
    do // HW interrupt mode
    {
      __WFI();
      if(IntCount !=0 ){
        IntCount=0;
        
        status = VL53L1_GetMultiRangingData(Dev, pMultiRangingData);
        RoiNumber=pMultiRangingData->RoiNumber;
        RoiStatus=pMultiRangingData->RoiStatus;
        no_of_object_found=pMultiRangingData->NumberOfObjectsFound;
        printf("Count=%5d, ", pMultiRangingData->StreamCount);
        printf("RoiNumber%1d, ", RoiNumber);
        printf("RoiStatus=%1d, ", RoiStatus);
        printf("#Objs=%1d, ", no_of_object_found);
          printf("status=%d, D=%5dmm, Signal=%2.2f Mcps, Ambient=%2.2f Mcps",
                 pMultiRangingData->RangeData[j].RangeStatus,
                 pMultiRangingData->RangeData[j].RangeMilliMeter,
                 pMultiRangingData->RangeData[j].SignalRateRtnMegaCps/65536.0,
                 pMultiRangingData->RangeData[j].AmbientRateRtnMegaCps/65536.0);

        printf ("\n\r");
        if (status==0){
          status = VL53L1_ClearInterruptAndStartMeasurement(Dev);
        }
        
      }
    }
    while(1);
  }
  else{
    do{ // polling mode
      status = VL53L1_GetMeasurementDataReady(Dev, &NewDataReady);
      HAL_Delay(1);
      if((!status)&&(NewDataReady!=0)){
        status = VL53L1_GetMultiRangingData(Dev, pMultiRangingData);
        RoiNumber=pMultiRangingData->RoiNumber;
        RoiStatus=pMultiRangingData->RoiStatus;

        printf("%1d,", RoiNumber);
        printf("%1d,", RoiStatus);
        printf("%d", pMultiRangingData->RangeData[0].RangeMilliMeter);
        printf ("\n\r");
        if (status==0){
          status = VL53L1_ClearInterruptAndStartMeasurement(Dev);
        }
      }
    }
    while (1);
  }
}

void SingleRoi(void){

}

void TestApi(void){
	uint8_t major=0,minor=0,build=0,revision=0;

	VL53L1_Version_t Version;
	VL53L1_Version_t *pVersion = &Version;
	VL53L1_DeviceInfo_t VL53L1_DeviceInfo;
	VL53L1_DeviceInfo_t *pVL53L1_DeviceInfo = &VL53L1_DeviceInfo;
	status = VL53L1_WaitDeviceBooted(Dev);
	status = VL53L1_DataInit(Dev);
	status = VL53L1_StaticInit(Dev);
	printf("Api Testing starts\n\r");

	status = VL53L1_GetVersion(pVersion);
	major = pVersion->major;
	minor = pVersion->minor;
	build = pVersion->build;

	revision = pVersion->revision;
	printf("major: %d\n\r", major);
	printf("minor: %d\n\r", minor);
	printf("build: %d\n\r", build);

	printf("revision: %d\n\r", revision);

	status = VL53L1_GetDeviceInfo(Dev, pVL53L1_DeviceInfo);
	printf("Product Name: %s\n\rProduct Type: %s\n\rProductId: %s\n\r", pVL53L1_DeviceInfo->Name, pVL53L1_DeviceInfo->Type, pVL53L1_DeviceInfo->ProductId);
}

/* USER CODE END 4 */

/**
* @brief  This function is executed in case of error occurrence.
* @param  None
* @retval None
*/
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
* @brief Reports the name of the source file and the source line number
* where the assert_param error has occurred.
* @param file: pointer to the source file name
* @param line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
  
}

#endif

/**
* @}
*/ 

/**
* @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
