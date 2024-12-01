
int main (void)               //Example 4
  { unsigned long PORT_1, PORT_2;

  setup_HW;
  while (1)
  { PORT_1 = 1;
    PORT_2 = 0x80000000;
    for (int m = 0; m <= 31; m++)
    {  I2C_Tx_2_integers(PORT_1, PORT_2);
      _delay_ms(60);
      PORT_1 = PORT_1 << 1;
      PORT_2 = PORT_2 >> 1;
    }
  }
  return 1;
  }
  
  
  
  int main (void)           //Example 5
  { unsigned int PORT_1, PORT_2;

 setup_HW;
  while (1)
  { PORT_1 = 1;
    PORT_2 = 0x8000;
    for (int m = 0; m <= 7; m++)
    { I2C_Tx_2_integers(PORT_1 | PORT_2,
      (PORT_1 << 8)  | (PORT_2 >> 8));
      _delay_ms(60);
      PORT_1 = PORT_1 << 1;
      PORT_2 = PORT_2 >> 1;
    }
  }
  return 1;
  } 