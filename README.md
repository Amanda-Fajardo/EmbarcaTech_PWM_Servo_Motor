# EmbarcaTech_PWM_Servo_Motor

O presente projeto conta com a manipulação do módulo PWM para o controle de um Servo Motor e contém uma demonstração feita na placa BitDogLab em que foi possível observar as alterações na intensidade do LED na mesma frequência que ocorreu o controle do Servo Motor.

# Funcionalidade

1. O Servo Motor inicia estando em um estado de 180º durante 5 segundos.
2. O Servo Motor passa para um estado de 90º durante 5 segundos.
3. O Servo Motor passa para um estado de 0º durante 5 segundos.
4. O Servo Motor passa a se movimentar de 0º a 180º até retornar ao estado inicial do loop.

# Como utilizar 


1. **Clone o repositório:**
```
git clone <https://github.com/Amanda-Fajardo/EmbarcaTech_PWM_Servo_Motor>
```

2. Tenha o VSCode instalado e configurado.
   
3. Tenha a extensão do Raspberry Pi Pico instalada e configurada.
   
4. Compile o programa utilizando o CMake:

```
mkdir build
cd build
cmake ..
make
```
5. Carregue o firmware no seu microcontrolador Raspberry Pi Pico para ver o seu funcionamento com LED.

6. Acesse o simulador online Wokwi na web ou instale sua extensão no VSCode e inicialize a simulação pelo arquivo `diagram.json`.

# Demonstração

https://drive.google.com/drive/folders/1Tky04_MCSOopj0PfryNsLbUlj8N-Yjpr
