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
  
  memoria[0] = 0x13;//Load A
  memoria[1] = 0x10;//Posição 16
  memoria[2] = 0x14;//Load B
  memoria[3] = 0x12;//Posição 18
  memoria[4] = 0x02;//Add
  memoria[5] = 0x15;//Store A
  memoria[6] = 0x0a;//Posição do store
  memoria[18] = 0x02;
  memoria[16] = 0x01;
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
      //Decodificar
      ibr = mbr & 0xffff; //Palavra da direita salva 
      mbr = mbr >> 16;
      ir = mbr >> 11;
      mar = mbr & 0x7ff;
      
    }else if (lr == 1){
      ir = ibr >> 11;
      mar = ibr & 0x7ff;
    }

    //Executar
    if (ir == 0x00)
    {
      //hlt
      
    }else if( ir == 0x01)
    {
      //nop
      if (lr == 1)
      {
        pc+=4;
      }else if(lr == 0){
        lr = 1;
      }
      
    }else if( ir == 0x02)
    {
      //add
      a = a + b;
    }else if( ir == 0x03)
    {
      //sub
      a = a - b;
    }else if( ir == 0x04)
    {
      //mul
      a = a * b;
    }else if( ir == 0x05)
    {
      //div
      a = a / b;
    }else if( ir == 0x06)
    {
      //cmp
      if (a == b)
      {
        e = 1;
      }else{
        e = 0;
      }

      if (a < b)
      {
        l = 1;
      }else{
        l = 0;
      }
      
      if (a > b)
      {
        g = 1;
      }else{
        g = 0;
      }
      
    }else if( ir == 0x07)
    {
      //xchg
      t = a;
      a = b;
      b = t;
    }else if( ir == 0x08)
    {
      //and
      a = a & b;
    }else if( ir == 0x09)
    {
      //or
      a = a | b;
    }else if( ir == 0x0a)
    {
      //xor
      a = a ^ b;
    }else if( ir == 0x0b)
    {
      //not
      a = !a;
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
      pc = memoria[mar];
    }else if( ir == 0x13)
    {
      //lda
      a = memoria[mar];
    }else if( ir == 0x14)
    {
      //ldb
      b = memoria[mar];
    }else if( ir == 0x15)
    {
      //sta
      memoria[mar] = a;
    }else if( ir == 0x16)
    {
      //stb
      memoria[mar] = b; 
    }else if( ir == 0x17)
    {
      //ldrb
      a = memoria[b];
    }else if( ir == 0x18)
    {
      //movial imm
      a = 0;

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

    printf("CPU: \nA: 0x%x\t\tB: 0x%x\t\tT: 0x%x\t\t\nMBR: 0x%x\tIBR: 0x%x\tMAR: 0x%x\tIMM: 0x%x\t\t\nPC: 0x%x\t\tIR: 0x%x\t\tLR: 0x%x\t\t\nE: 0x%x\t\tL: 0x%x\t\tG: 0x%x\n\n", a, b, t, mbr, ibr, mar, imm, pc, ir, lr, e, l, g);
    printf("Memoria:\n");

    for (int i = 0; i < 0x99; i++)
    {
      printf("%d:0x%x ",i, memoria[i]);  
    }
    printf("\n");
    printf("\n\nAperte uma tecla para iniciar o proximo ciclo, ou Ctrl+C para finalizar\n");
    getch();
    i++;
    pc +=4;

    } while (mar != 999);
  return 0;
}
