
_main:

;microproject.c,20 :: 		void main()
;microproject.c,24 :: 		TRISC = 0x00;
	CLRF       TRISC+0
;microproject.c,25 :: 		PORTC = 0x00;
	CLRF       PORTC+0
;microproject.c,26 :: 		ADC_Init();                   // Initialize ADC
	CALL       _ADC_Init+0
;microproject.c,27 :: 		Lcd_Init();                   // Initialize LCD
	CALL       _Lcd_Init+0
;microproject.c,28 :: 		Lcd_Cmd(_LCD_CLEAR);          // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;microproject.c,29 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);     // Cursor off
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;microproject.c,32 :: 		Lcd_Out(1, 1, "    Irrigation ");  //anything you want to print
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,33 :: 		Lcd_Out(2, 1, "    system");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,34 :: 		delay_ms(2000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	DECFSZ     R11+0, 1
	GOTO       L_main0
	NOP
;microproject.c,35 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;microproject.c,36 :: 		Lcd_Out(1, 1, "    Automation ");  //anything you want to print
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr3_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,37 :: 		Lcd_Out(2, 1, "    system");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr4_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,38 :: 		delay_ms(2000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main1:
	DECFSZ     R13+0, 1
	GOTO       L_main1
	DECFSZ     R12+0, 1
	GOTO       L_main1
	DECFSZ     R11+0, 1
	GOTO       L_main1
	NOP
;microproject.c,39 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;microproject.c,40 :: 		Lcd_Out(1, 1, "  SOIL MOISTURE ");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr5_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,41 :: 		Lcd_Out(2, 1, " automation");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr6_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,42 :: 		delay_ms(2000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
;microproject.c,43 :: 		Lcd_Cmd(_LCD_CLEAR);          // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;microproject.c,45 :: 		while(1)
L_main3:
;microproject.c,47 :: 		source=Adc_Read(1);
	MOVLW      1
	MOVWF      FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	CALL       _Word2Double+0
	MOVF       R0+0, 0
	MOVWF      _source+0
	MOVF       R0+1, 0
	MOVWF      _source+1
	MOVF       R0+2, 0
	MOVWF      _source+2
	MOVF       R0+3, 0
	MOVWF      _source+3
;microproject.c,49 :: 		if(source>600)
	MOVF       R0+0, 0
	MOVWF      R4+0
	MOVF       R0+1, 0
	MOVWF      R4+1
	MOVF       R0+2, 0
	MOVWF      R4+2
	MOVF       R0+3, 0
	MOVWF      R4+3
	MOVLW      0
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
	MOVLW      22
	MOVWF      R0+2
	MOVLW      136
	MOVWF      R0+3
	CALL       _Compare_Double+0
	MOVLW      1
	BTFSC      STATUS+0, 0
	MOVLW      0
	MOVWF      R0+0
	MOVF       R0+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main5
;microproject.c,51 :: 		PORTC = 0b11111101;                  //motor on
	MOVLW      253
	MOVWF      PORTC+0
;microproject.c,52 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main6:
	DECFSZ     R13+0, 1
	GOTO       L_main6
	DECFSZ     R12+0, 1
	GOTO       L_main6
	DECFSZ     R11+0, 1
	GOTO       L_main6
	NOP
	NOP
;microproject.c,53 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;microproject.c,54 :: 		Lcd_Out(1,5, "Dry Soil");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      5
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr7_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,55 :: 		Lcd_Out(2,5, "Motor On");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      5
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr8_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,56 :: 		}
L_main5:
;microproject.c,58 :: 		if(source<=600)
	MOVF       _source+0, 0
	MOVWF      R4+0
	MOVF       _source+1, 0
	MOVWF      R4+1
	MOVF       _source+2, 0
	MOVWF      R4+2
	MOVF       _source+3, 0
	MOVWF      R4+3
	MOVLW      0
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
	MOVLW      22
	MOVWF      R0+2
	MOVLW      136
	MOVWF      R0+3
	CALL       _Compare_Double+0
	MOVLW      1
	BTFSS      STATUS+0, 0
	MOVLW      0
	MOVWF      R0+0
	MOVF       R0+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main7
;microproject.c,60 :: 		PORTC = 0b00000000;
	CLRF       PORTC+0
;microproject.c,61 :: 		delay_ms(500);                  //motor off
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
	DECFSZ     R11+0, 1
	GOTO       L_main8
	NOP
	NOP
;microproject.c,62 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;microproject.c,63 :: 		Lcd_Out(1,5, "Humid Soil");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      5
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr9_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,64 :: 		Lcd_Out(2,5, "Motor OFF");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      5
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr10_microproject+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;microproject.c,65 :: 		}
L_main7:
;microproject.c,66 :: 		}
	GOTO       L_main3
;microproject.c,68 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
