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
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include <string.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "i2c-lcd.h"
#include "CLCD_I2C.h"
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
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint16_t data[2];
uint16_t value1 ;
uint16_t value2;
int dem=0;
int dem1 = 0;
int Q1 = 0;
int Q2 = 0;
int Q3 = 0;
int Q4 = 0;
int Q5 = 0;
int Q6 = 0;
int k1 =0; 
int k2 = 0;
int i ;
int l;
int thoigian=1000;



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
  MX_DMA_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
		lcd_init();

	lcd_goto_XY(1,0);
	lcd_send_string("DO AN MON HOC4");
	lcd_goto_XY(2,0);
	lcd_send_string("DAN PHOI TU DONG");
	HAL_Delay(3000);
			for (int i=0;i<3;i++){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,0);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,0);
		HAL_Delay(1000);




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1); //bat led pc13 vi dieu khien
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,0);// tat led 
		HAL_Delay(500);
		
		HAL_ADC_Start_DMA(&hadc1,(uint32_t*)data,2); //truyen ADC vao bien con tro data 32bit
		HAL_Delay(50);
		HAL_ADC_Stop_DMA(&hadc1); // luu gia tri vao thanh ghi dma
		
		value1 = data[0];         //tin hieu alalog mua
		value2 = data[1];         // tin hieu alalog anh sang
		
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1); //bat led pc13 vi dieu khien
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,0);// tat led 
		HAL_Delay(500);// tin hieu alalog anh sang
		
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_3)==0){   // neu nhan PA3
			    for(int x=4000; x >0; x--);          // chong rung nut nhan 
			    dem = dem + 1 ;}                         
		
	  if(dem % 2 == 0) {
		 
		 Lcd_Ghi_Lenh(0x80);
		 sprintf(&M[0],"che do:tu dong                                                                                                                                                                                                                                                                                                                                                                                           ");
     Lcd_Ghi_chuoi(&M[0]);
       
     HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1); 
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0); //thuc hien qua trinh tu dong
		 
		 if(value1 <=1550 && value2 <= 2400) // ban ngay co mua. thuc hien dong cua  {
		 {      Lcd_Ghi_Lenh(0xc0);
		        sprintf(&M[0],"dong:ngay co mua         ");
			      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1);
					  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);
            Lcd_Ghi_chuoi(&M[0]);
					  if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0)
                                                         {Q2=0;}//
					
					
				            // kiem tra dong cua hay khong neu dong thi dong thi giu nguyen neu dang mo thi thuc hien qua  trinh dong 					      	
           	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0 && Q1 ==0){Q2=0;}
				            // kiem tra dong cua hay khong neu dong thi dong thi giu nguyen neu dang mo thi thuc hien qua  trinh dong 					      
					
					  if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0 && Q2 ==0){
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
																								 HAL_Delay(thoigian);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,0);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
																								 Q2 = 1; Q1=0;}
            
														 
	  }   if(value1 <= 1550 &&  value2 > 2400) // ban ngay khong mua. thuc hien mo 
			  {  
											 Lcd_Ghi_Lenh(0xc0);
											 sprintf(&M[0],"mo:ngay khum mua       ");
											 Lcd_Ghi_chuoi(&M[0]);
					             
					              HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,0);
					              HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,0);
											 //kiem tra dong . neu dong thi mo .
											 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0 && Q3 ==0){
																													 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
																													 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
																													 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
																													 HAL_Delay(thoigian);
																													 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,0);
																													 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
																													 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
																																		 Q3 = 1;} 
											 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0 && Q4 ==0)
																																		{Q3 = 0;}
																							 
																							 
											 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0)//
																																		{Q3 = 0;}

																		 
				 }
				     
				 
				 
				// buoi toi thi thuc hien dong cua 
			  if(value1 > 1550) { Lcd_Ghi_Lenh(0xc0);
		          sprintf(&M[0],"dong: Toi                  ");
              Lcd_Ghi_chuoi(&M[0]);
					    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1);
					    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);
						 
				if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0){k2=0;}//
				            // kiem tra dong cua hay khong neu dong thi dong thi giu nguyen neu dang mo thi thuc hien qua  trinh dong 
						  // ban ngay co mua. thuc hien dong cua  {
        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0 && k1 ==0){k2=0;}
				            // kiem tra dong cua hay khong neu dong thi dong thi giu nguyen neu dang mo thi thuc hien qua  trinh dong 					      
					
				if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0 && k2 ==0){
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
																								 HAL_Delay(thoigian);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,0);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
																								 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
																								 k2 = 1; k1=0;}
                    						
			    }
			 
			  
				 
	 }
	if(dem % 2 ==1)
		{ 
		     
          Lcd_Ghi_Lenh(0x80);
		      sprintf(&M[0],"che do:thu cong      ");
          Lcd_Ghi_chuoi(&M[0]);	
			 
			
		 	 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0){
		      Lcd_Ghi_Lenh(0xc0);
		      sprintf(&M[0],"mo                    ");
          Lcd_Ghi_chuoi(&M[0]);
			    
			 }

			 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0){
		                Lcd_Ghi_Lenh(0xc0);
										sprintf(&M[0],"dong                  ");
				            Lcd_Ghi_chuoi(&M[0]);
				           
     }
		 
		 
		 
		 
		 // thuc hien chuyen sang che do thu cong 
		      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0); HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1); 
	        if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)==0)
						{
									 for(int l=4000; l >0; l--);
									 Q6=Q6+1;
									 Q5=Q5+1;
						       if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0 && Q5%2==1){
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
									 
									 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==1){
		                  Lcd_Ghi_Lenh(0xc0);
											sprintf(&M[0],"thuc hien mo---------");
											Lcd_Ghi_chuoi(&M[0]);}
									 HAL_Delay(thoigian);
									 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,0);
									 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
											HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,0);
				              HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,0);
								   

						}
								
								if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1 && Q6%2==0){
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
									 
									 if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==1){
		                  Lcd_Ghi_Lenh(0xc0);
											sprintf(&M[0],"thuc hien dong---------");
											Lcd_Ghi_chuoi(&M[0]);}				
									 HAL_Delay(thoigian);
									 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,0);
									 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1);
				           HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);
								}
								       	
		           if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==1 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0){
		                  Lcd_Ghi_Lenh(0xc0);
											sprintf(&M[0],"mo                      ");
											Lcd_Ghi_chuoi(&M[0]);
							         }
            			
											
							if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0 && HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0&& HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==0){
													Lcd_Ghi_Lenh(0xc0);
													sprintf(&M[0],"dong                   ");
													Lcd_Ghi_chuoi(&M[0]);
								          
            }
					}			
	       }	
       }
  /* USER CODE END 3 */
}


void Lcd_Ghi_Lenh(char malenh)
{
 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);//RS=0
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);//LCD_RW=0
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);//LCD_EN= 1
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,(malenh>>4)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,(malenh>>5)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,(malenh>>6)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,(malenh>>7)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);//LCD_EN=0
HAL_Delay(10); //5ms
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);//LCD_EN= 1;
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,(malenh&0x01));
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,(malenh>>1)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,(malenh>>2)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,(malenh>>3)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);//LCD_EN=0
HAL_Delay(10); //5ms
}



void Lcd_Ghi_Dulieu(char dulieu)
{
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);//RS=0
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);//LCD_RW=0
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);//LCD_EN= 1
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,(dulieu>>4)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,(dulieu>>5)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,(dulieu>>6)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,(dulieu>>7)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);//LCD_EN=0
HAL_Delay(10); //5ms
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);//LCD_EN= 1
	
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,(dulieu&0x01));
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,(dulieu>>1)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,(dulieu>>2)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,(dulieu>>3)&0x01);
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);//LCD_EN=0
HAL_Delay(10); //5ms
}

void Lcd_Cauhinh(void)
{
Lcd_Ghi_Lenh(0x03); //Bat dau
Lcd_Ghi_Lenh(0x02); // tro ve dau dong
Lcd_Ghi_Lenh(0x28);// Giao tiep Vi dieu khien 4 4 chân
Lcd_Ghi_Lenh(0x06);// Dua con tro den vi tri tiep theo
Lcd_Ghi_Lenh(0x0c);// Baat hien thi, tang con tro
Lcd_Ghi_Lenh(0x01); // Xóa màn hình
}
void Lcd_Ghi_chuoi (char *str)
{
while(*str)
{
Lcd_Ghi_Dulieu(*str);
str++;
}
}













/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 2;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA3 PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA5 PA6 PA8 PA9
                           PA11 PA12 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 PB5 PB6
                           PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
