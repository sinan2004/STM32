/* USER CODE BEGIN PV */
const uint8_t Sine_Table[256] ={50,51,52,54,55,56,57,59,60,61,62,63,65,66,67,68,69,70,71,72,74,75,76,77,78,79,80,81,
								82,83,84,84,85,86,87,88,89,89,90,91,92,92,93,94,94,95,95,96,96,97,97,97,98,98,99,99,
								99,99,99,100,100,100,100,100,100,100,100,100,100,100,99,99,99,99,99,98,98,97,97,97,
								96,96,95,95,94,94,93,92,92,91,90,89,89,88,87,86,85,84,84,83,82,81,80,79,78,77,76,
								75,74,72,71,70,69,68,67,66,65,63,62,61,60,59,57,56,55,54,52,51,50,49,48,46,45,44,
								43,41,40,39,38,37,35,34,33,32,31,30,29,28,26,25,24,23,22,21,20,19,18,17,16,16,15,
								14,13,12,11,11,10,9,8,8,7,6,6,5,5,4,4,3,3,3,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,
								1,1,1,1,2,2,3,3,3,4,4,5,5,6,6,7,8,8,9,10,11,11,12,13,14,15,16,16,17,18,19,20,21,22,
								23,24,25,26,28,29,30,31,32,33,34,35,37,38,39,40,41,43,44,45,46,48,49 };
uint16_t phase_increment = 0;
uint16_t increment = 0 ;
uint8_t sin_pos = 0 ;
uint16_t on_call = 0 ;
uint16_t frequency = 50;

/* USER CODE END PV */


  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
   HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
   HAL_TIM_Base_Start_IT(&htim1);
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,0);
  /* USER CODE END 2 */

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{


    if(htim->Instance == TIM1)
    {
    	on_call ++ ;
    	increment = frequency*65;

    	TIM1->CCR2 = Sine_Table[sin_pos];
    	phase_increment += increment;
    	sin_pos = phase_increment >>8;

    }

}

/* USER CODE END 4 */
