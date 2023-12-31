/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"
#include "usb_host.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */
char veri[];
char gelen_veri[];
int binary = 0 ;
int binary_input = 0;
int b1,b2,b3,b4
	,b5,b6,b7,b8;  // output binary değişkenleri
int g1,g2,g3,g4
	,g5,g6,g7,g8; // input binary değişkenleri
int gelen;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_HOST_Init();
  MX_USART2_UART_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    /* USER CODE BEGIN 3 */
       binary = veri[0];
       b1 = binary/128;
       if(b1==1){
    	   HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_SET);

       	}else if(b1==0){
       		HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_RESET);

       	}
       gelen = HAL_GPIO_ReadPin(GPIOC, giris_Pin);
       g1 = gelen*128;

       for(int i = 0 ; i < 5000 ; i++){

       	}
       b2 = (binary-(b1*128))/64 ;
       if(b2==1){
    	   HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_SET);

              	}else if(b2==0){
              		HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_RESET);

              	}
       gelen = HAL_GPIO_ReadPin(GPIOC, giris_Pin);
       g2 = gelen*64;
       for(int i = 0 ; i < 5000 ; i++){

       	}
       b3 = (binary-(b1*128)-(b2*64))/32;
       if(b3==1){
    	   HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_SET);

             	}else if(b3==0){
             		HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_RESET);

             	}

       gelen = HAL_GPIO_ReadPin(GPIOC, giris_Pin);
       g3 = gelen*32;
       for(int i = 0 ; i < 5000 ; i++){

       	}
       b4 = (binary-(b1*128)-(b2*64)-(b3*32))/16;
       if(b4==1){
    	   HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_SET);

             	}else if(b4==0){
             		HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_RESET);

             	}

       gelen = HAL_GPIO_ReadPin(GPIOC, giris_Pin);
       g4 = gelen*16;
       for(int i = 0 ; i < 5000 ; i++){

       	}
       b5 = (binary-(b1*128)-(b2*64)-(b3*32)-(b4*16))/8;
       if(b5==1){
    	   HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_SET);

             	}else if(b5==0){
             		HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_RESET);

             	}

       gelen = HAL_GPIO_ReadPin(GPIOC, giris_Pin);
       g5= gelen*8;
       for(int i = 0 ; i < 5000 ; i++){

       	}
       b6 = (binary-(b1*128)-(b2*64)-(b3*32)-(b4*16)-(b5*8))/4;
       if(b6==1){
    	   HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_SET);

             	}else if(b6==0){
             		HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_RESET);

             	}

       gelen = HAL_GPIO_ReadPin(GPIOC, giris_Pin);
       g6 = gelen*4;
       for(int i = 0 ; i < 5000 ; i++){

       	}
       b7 = (binary-(b1*128)-(b2*64)-(b3*32)-(b4*16)-(b5*8)-(b6*4))/2;
       if(b7==1){
    	   HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_SET);

             	}else if(b7==0){
             		HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_RESET);

             	}

       gelen = HAL_GPIO_ReadPin(GPIOC, giris_Pin);
       g7 = gelen*2;
       for(int i = 0 ; i < 5000 ; i++){

       	}
       b8 = binary-(b1*128)-(b2*64)-(b3*32)-(b4*16)-(b5*8)-(b6*4)-(b7*2);
       if(b8==1){
    	   HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_SET);

             	}else if(b8==0){
             		HAL_GPIO_WritePin(GPIOA, cikis_Pin, GPIO_PIN_RESET);

             	}

       gelen = HAL_GPIO_ReadPin(GPIOC, giris_Pin);
       g8 = gelen;
       for(int i = 0 ; i < 5000 ; i++){

       	}
       binary_input = g1+g2+g3+g4+g5+g6+g7+g8;
       gelen_veri[0] = binary_input;
       for(int i = 0 ; i < 5000 ; i++){

       	}
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
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
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(cikis_GPIO_Port, cikis_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : giris_Pin */
  GPIO_InitStruct.Pin = giris_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(giris_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PC0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : cikis_Pin */
  GPIO_InitStruct.Pin = cikis_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(cikis_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
