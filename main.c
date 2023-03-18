#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

unsigned char memoria[154]; //cada char 8 bits //zerar todo o vetor com zero// variaveis globais para os registradores
unsigned int mbr;
unsigned short int mar;
unsigned short int ibr;
unsigned char ir;
unsigned short int imm;
unsigned short int pc = 0;
unsigned char e, l, g;
unsigned char lr = 0;
unsigned short int a, b, t; 
int i = 0;
int next = 0;
//Carregando programa manualmente


int main()
{ 
  //Zerar a memoria
  for (int i = 0; i < 154; i++)
  {
    memoria[i]=0x00;
  }
  
  memoria[0] = 0xaa;
  memoria[1] = 0xab;
  memoria[2] = 0xef;
  memoria[3] = 0x0e;
  memoria[4] = 0x11;
  //mar = pc
  //mbr = mem[mar] 40
  //mar++
  //mbr = mbr<<8 deslocar para esquerda para receber proxima palavra
  //mbr = mbr || mem[mar 41]
  //mar++
  //ibr = mbr & 0xffff para deixar somente os 16 bits menos significativos dos 32 que estavam no mbr
  //mbr = mbr >> 16;
  //mar = mbr & 0x7ff para pegar um 11 bits menos significativos para obter o endereço de memoria
  //ir = mbr >> 11 para obter apenas o opcode
  //

  
  do
  { 
    printf("CPU: \nA: 0x%x\t\tB: 0x%x\t\tT: 0x%x\t\t\nMBR: 0x%x\tMAR: 0x%x\tIMM: 0x%x\t\t\nPC: 0x%x\t\tIR: 0x%x\tLR: 0x%x\t\t\nE: 0x%x\t\tL: 0x%x\t\tG: 0x%x\n\n", a, b, t, mbr, mar, imm, pc, ir, lr, e, l, g);
    printf("Memoria:\n");

    for (int i = 0; i < 0x99; i++)
    {
      printf("%d:0x%x ",i, memoria[i]);  
    }
    printf("\n");
    printf("\n\nAperte uma tecla para iniciar o proximo ciclo, ou Ctrl+C para finalizar\n");
    getch();
    i++;

    //Buscar
    if (lr == 0)
    {
      mar = pc;
      mbr = memoria[mar];
      mar++;
      mbr = mbr <<8;
      mbr = mbr | memoria[mar];
      mar++;
      mbr = mbr <<8;
      mbr = mbr | memoria[mar];
      mar++;
      mbr = mbr <<8;
      mbr = mbr | memoria[mar];
      mar++;
      //Decodificar
      ibr = mbr & 0xffff;
      mbr = mbr >> 16;
      ir = mbr >>11;
      mar = mbr & 0x7ff;
      
    }else if (lr == 1){

    }

    //Executar
    if (ir == 0x00)
    {
      //hlt
    }else if( ir == 0x01)
    {
      //nop
    }else if( ir == 0x02)
    {
      //add
    }else if( ir == 0x03)
    {
      //sub
    }else if( ir == 0x04)
    {
      //mul
    }else if( ir == 0x05)
    {
      //div
    }else if( ir == 0x06)
    {
      //cmp
    }else if( ir == 0x07)
    {
      //xchg
    }else if( ir == 0x08)
    {
      //and
    }else if( ir == 0x09)
    {
      //or
    }else if( ir == 0x0a)
    {
      //xor
    }else if( ir == 0x0b)
    {
      //not
    }else if( ir == 0x0c)
    {
      //je
    }else if( ir == 0x0d)
    {
      //jne
    }else if( ir == 0x0e)
    {
      //jl
    }else if( ir == 0x0f)
    {
      //jle
    }else if( ir == 0x10)
    {
      //jg
    }else if( ir == 0x11)
    {
      //jge
    }else if( ir == 0x12)
    {
      //jmp
    }else if( ir == 0x13)
    {
      //lda
    }else if( ir == 0x14)
    {
      //ldb
    }else if( ir == 0x15)
    {
      //sta
    }else if( ir == 0x16)
    {
      //stb 
    }else if( ir == 0x17)
    {
      //ldrb 
    }else if( ir == 0x18)
    {
      //movial imm
    }else if( ir == 0x19)
    {
      //moviah imm
    }else if( ir == 0x1a)
    {
      //addia imm
    }else if( ir == 0x1b)
    {
      //subia imm
    }else if( ir == 0x1c)
    {
      //mulia imm
    }else if( ir == 0x1d)
    {
      //divia imm
    }else if( ir == 0x1e)
    {
      //lsh imm
    }else if( ir == 0x1f)
    {
      //rsh imm
    }
    
    } while (memoria[i] != 0x00);
  return 0;
}
