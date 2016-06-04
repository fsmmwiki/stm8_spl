
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8S_UART1_H
#define __STM8S_UART1_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @addtogroup UART1_Exported_Types
  * @{
  */


/**
  * @brief  UART1 Irda Modes
  */

typedef enum { UART1_IRDAMODE_NORMAL    = (uint8_t)0x00, /**< 0x00 Irda Normal Mode   */
               UART1_IRDAMODE_LOWPOWER  = (uint8_t)0x01  /**< 0x01 Irda Low Power Mode */
             } UART1_IrDAMode_TypeDef;

/**
  * @brief  UART1 WakeUP Modes
  */
typedef enum { UART1_WAKEUP_IDLELINE       = (uint8_t)0x00, /**< 0x01 Idle Line wake up                */
               UART1_WAKEUP_ADDRESSMARK    = (uint8_t)0x08  /**< 0x02 Address Mark wake up          */
             } UART1_WakeUp_TypeDef;

/**
  * @brief  UART1 LIN Break detection length possible values
  */
typedef enum { UART1_LINBREAKDETECTIONLENGTH_10BITS = (uint8_t)0x00, /**< 0x01 10 bits Lin Break detection            */
               UART1_LINBREAKDETECTIONLENGTH_11BITS = (uint8_t)0x01  /**< 0x02 11 bits Lin Break detection          */
             } UART1_LINBreakDetectionLength_TypeDef;

/**
  * @brief  UART1 stop bits possible values
  */

typedef enum { UART1_STOPBITS_1   = (uint8_t)0x00,    /**< One stop bit is  transmitted at the end of frame*/
               UART1_STOPBITS_0_5 = (uint8_t)0x10,    /**< Half stop bits is transmitted at the end of frame*/
               UART1_STOPBITS_2   = (uint8_t)0x20,    /**< Two stop bits are  transmitted at the end of frame*/
               UART1_STOPBITS_1_5 = (uint8_t)0x30     /**< One and half stop bits*/
             } UART1_StopBits_TypeDef;

/**
  * @brief  UART1 parity possible values
  */
typedef enum { UART1_PARITY_NO     = (uint8_t)0x00,      /**< No Parity*/
               UART1_PARITY_EVEN   = (uint8_t)0x04,      /**< Even Parity*/
               UART1_PARITY_ODD    = (uint8_t)0x06       /**< Odd Parity*/
             } UART1_Parity_TypeDef;

/**
  * @brief  UART1 Synchrone modes
  */
typedef enum { UART1_SYNCMODE_CLOCK_DISABLE    = (uint8_t)0x80, /**< 0x80 Sync mode Disable, SLK pin Disable */
               UART1_SYNCMODE_CLOCK_ENABLE     = (uint8_t)0x08, /**< 0x08 Sync mode Enable, SLK pin Enable     */
               UART1_SYNCMODE_CPOL_LOW         = (uint8_t)0x40, /**< 0x40 Steady low value on SCLK pin outside transmission window */
               UART1_SYNCMODE_CPOL_HIGH        = (uint8_t)0x04, /**< 0x04 Steady high value on SCLK pin outside transmission window */
               UART1_SYNCMODE_CPHA_MIDDLE      = (uint8_t)0x20, /**< 0x20 SCLK clock line activated in middle of data bit     */
               UART1_SYNCMODE_CPHA_BEGINING    = (uint8_t)0x02, /**< 0x02 SCLK clock line activated at beginning of data bit  */
               UART1_SYNCMODE_LASTBIT_DISABLE  = (uint8_t)0x10, /**< 0x10 The clock pulse of the last data bit is not output to the SCLK pin */
               UART1_SYNCMODE_LASTBIT_ENABLE   = (uint8_t)0x01  /**< 0x01 The clock pulse of the last data bit is output to the SCLK pin */
             } UART1_SyncMode_TypeDef;

/**
  * @brief  UART1 Word length possible values
  */
typedef enum { UART1_WORDLENGTH_8D = (uint8_t)0x00,/**< 0x00 8 bits Data  */
               UART1_WORDLENGTH_9D = (uint8_t)0x10 /**< 0x10 9 bits Data  */
             } UART1_WordLength_TypeDef;

/**
  * @brief  UART1 Mode possible values
  */
typedef enum { UART1_MODE_RX_ENABLE     = (uint8_t)0x08,  /**< 0x08 Receive Enable */
               UART1_MODE_TX_ENABLE     = (uint8_t)0x04,  /**< 0x04 Transmit Enable */
               UART1_MODE_TX_DISABLE    = (uint8_t)0x80,  /**< 0x80 Transmit Disable */
               UART1_MODE_RX_DISABLE    = (uint8_t)0x40,  /**< 0x40 Single-wire Half-duplex mode */
               UART1_MODE_TXRX_ENABLE   = (uint8_t)0x0C  /**< 0x0C Transmit Enable and Receive Enable */
             } UART1_Mode_TypeDef;

/**
  * @brief  UART1 Flag possible values
  */
typedef enum { UART1_FLAG_TXE   = (uint16_t)0x0080, /*!< Transmit Data Register Empty flag */
               UART1_FLAG_TC    = (uint16_t)0x0040, /*!< Transmission Complete flag */
               UART1_FLAG_RXNE  = (uint16_t)0x0020, /*!< Read Data Register Not Empty flag */
               UART1_FLAG_IDLE  = (uint16_t)0x0010, /*!< Idle line detected flag */
               UART1_FLAG_OR    = (uint16_t)0x0008, /*!< OverRun error flag */
               UART1_FLAG_NF    = (uint16_t)0x0004, /*!< Noise error flag */
               UART1_FLAG_FE    = (uint16_t)0x0002, /*!< Framing Error flag */
               UART1_FLAG_PE    = (uint16_t)0x0001, /*!< Parity Error flag */
               UART1_FLAG_LBDF  = (uint16_t)0x0210, /*!< Line Break Detection Flag */
               UART1_FLAG_SBK   = (uint16_t)0x0101  /*!< Send Break characters Flag */
             } UART1_Flag_TypeDef;

/**
  * @brief  UART1 Interrupt definition
  * UART1_IT possible values
  * Elements values convention: 0xZYX
  * X: Position of the corresponding Interrupt
  *   - For the following values, X means the interrupt position in the CR2 register.
  *     UART1_IT_TXE
  *     UART1_IT_TC
  *     UART1_IT_RXNE
  *     UART1_IT_IDLE 
  *     UART1_IT_OR 
  *   - For the UART1_IT_PE value, X means the flag position in the CR1 register.
  *   - For the UART1_IT_LBDF value, X means the flag position in the CR4 register.
  * Y: Flag position
  *  - For the following values, Y means the flag (pending bit) position in the SR register.
  *     UART1_IT_TXE
  *     UART1_IT_TC
  *     UART1_IT_RXNE
  *     UART1_IT_IDLE 
  *     UART1_IT_OR
  *     UART1_IT_PE
  *  - For the UART1_IT_LBDF value, Y means the flag position in the CR4 register.
  * Z: Register index: indicate in which register the dedicated interrupt source is:
  *  - 1==> CR1 register
  *  - 2==> CR2 register
  *  - 3==> CR4 register
  */
typedef enum { UART1_IT_TXE        = (uint16_t)0x0277, /*!< Transmit interrupt */
               UART1_IT_TC         = (uint16_t)0x0266, /*!< Transmission Complete interrupt */
               UART1_IT_RXNE       = (uint16_t)0x0255, /*!< Receive interrupt */
               UART1_IT_IDLE       = (uint16_t)0x0244, /*!< IDLE line interrupt */
               UART1_IT_OR         = (uint16_t)0x0235, /*!< Overrun Error interrupt */
               UART1_IT_PE         = (uint16_t)0x0100, /*!< Parity Error interrupt */
               UART1_IT_LBDF       = (uint16_t)0x0346, /**< LIN break detection interrupt */
               UART1_IT_RXNE_OR    = (uint16_t)0x0205  /*!< Receive/Overrun interrupt */
             } UART1_IT_TypeDef;

/**
  * @}
  */


void UART1_DeInit(void);
void UART1_Init(uint32_t BaudRate, UART1_WordLength_TypeDef WordLength, 
                UART1_StopBits_TypeDef StopBits, UART1_Parity_TypeDef Parity, 
                UART1_SyncMode_TypeDef SyncMode, UART1_Mode_TypeDef Mode);
void UART1_ITConfig(UART1_IT_TypeDef UART1_IT, FunctionalState NewState);
void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp);
void UART1_ReceiverWakeUpCmd(FunctionalState NewState);
uint8_t UART1_ReceiveData8(void);
uint16_t UART1_ReceiveData9(void);
void UART1_SendData8(uint8_t Data);
void UART1_SendData9(uint16_t Data);
void UART1_SendBreak(void);
void UART1_SetAddress(uint8_t UART1_Address);
void UART1_SetGuardTime(uint8_t UART1_GuardTime);
void UART1_SetPrescaler(uint8_t UART1_Prescaler);
FlagStatus UART1_GetFlagStatus(UART1_Flag_TypeDef UART1_FLAG);
void UART1_ClearFlag(UART1_Flag_TypeDef UART1_FLAG);
ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT);
void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT);

#define UART1_Enable UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD); 
#define UART1_Disable    UART1->CR1 |= UART1_CR1_UARTD;  
#define UART1_HalfDuplexCmd_Enable UART1->CR5 |= UART1_CR5_HDSEL;  /**< UART1 Half Duplex Enable  */
#define UART1_HalfDuplexCmd_Disable  UART1->CR5 &= (uint8_t)~UART1_CR5_HDSEL;
#define UART1_IrDAConfig_Normal UART1->CR5 &= ((uint8_t)~UART1_CR5_IRLP);
#define UART1_IrDAConfig_No_Normal UART1->CR5 |= UART1_CR5_IRLP;
#define UART1_IrDA_Enable UART1->CR5 |= UART1_CR5_IREN;
#define UART1_IrDA_Disable  UART1->CR5 &= ((uint8_t)~UART1_CR5_IREN);    
#define UART1_LINBreakDetectionConfig_10 UART1->CR4 &= ((uint8_t)~UART1_CR4_LBDL);
#define UART1_LINBreakDetectionConfig_11 UART1->CR4 |= UART1_CR4_LBDL;
#define UART1_LIN_Enable UART1->CR3 |= UART1_CR3_LINEN;
#define UART1_LIN_Disable UART1->CR3 &= ((uint8_t)~UART1_CR3_LINEN);
#define UART1_SmartCardCmd_Enable UART1->CR5 |= UART1_CR5_SCEN;
#define UART1_SmartCardCmd_Disable    UART1->CR5 &= ((uint8_t)(~UART1_CR5_SCEN));
#define UART1_SmartCardNACKCmd_Enable UART1->CR5 |= UART1_CR5_NACK;
#define UART1_SmartCardNACKCmd_Disable UART1->CR5 &= ((uint8_t)~(UART1_CR5_NACK));
#define UART1_ReceiverWakeUpCmd_Enable UART1->CR2 |= UART1_CR2_RWU;
#define UART1_ReceiverWakeUpCmd_Disable UART1->CR2 &= ((uint8_t)~UART1_CR2_RWU);
#define UART_ReadBuf  ((uint8_t)UART1->DR);
#define UART_WriteBuf UART1->DR;
#define UART1_SendBreak UART1->CR2 |= UART1_CR2_SBK;;
#define UART_GuardTime UART1->GTR 
#define WaitSend while((UART1->SR & (uint8_t)UART1_FLAG_TXE) == (uint8_t)0x00);
#define WaitStop while((UART1->SR & (uint8_t)UART1_FLAG_TC) == (uint8_t)0x00);
#define Wait wt=0; while(wt<20000) wt++;
#define WaitRecive if((UART1->SR & (uint8_t)UART1_FLAG_RXNE) != (uint8_t)0x00)
/**
  * @brief  Sets the system clock prescaler.
  * @note   IrDA Low Power mode or smartcard mode should be enabled
  * @note   This function is related to SmartCard and IrDa mode.
  * @param  UART1_Prescaler: specifies the prescaler clock.
  *         This parameter can be one of the following values:
  *         @par IrDA Low Power Mode
  *         The clock source is divided by the value given in the register (8 bits)
  *         - 0000 0000 Reserved
  *         - 0000 0001 divides the clock source by 1
  *         - 0000 0010 divides the clock source by 2
  *         - ...
  *        @par Smart Card Mode
  *        The clock source is divided by the value given in the register
  *        (5 significant bits) multiplied by 2
  *         - 0 0000 Reserved
  *         - 0 0001 divides the clock source by 2
  *         - 0 0010 divides the clock source by 4
  *         - 0 0011 divides the clock source by 6
  *         - ...
  * @retval None
  */
#define UART_Prescale UART1->PSCR;
/**
  * @}
  */

#endif /* __STM8S_UART1_H */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
