# Trabalho 1 de Estrutura de Dados

Para a utilização do programa, é necessário saber o seu Sistema Operacional.

<details open>
  <summary>Windows</summary>

#### Verificar se o Cygwin ou MinGW estão instalados

Se tiver, só é necessário abrir o Terminal, e utilizar o comando na pasta root do código
```bash
mingw32-make all
```
</details>

<details>
  <summary>Linux</summary>

#### Apenas abrir o terminal

Para Linux, o comando make já está disponível por padrão.
Então só é necessário abrir o Terminal, e utilizar o comando a seguir na pasta root do código
```bash
make all
```

</details>

Nesse projeto, existem alguns Tipos Abstratos de Dados (TADs), o Patient, o Exam, a Condition, a XRMachine, e o Report.

Patient:
```c
struct patient {
    int id;
    char* name;
    int timestamp;
};
```

Exam:
```c
struct exam {
    int id;
    int xr_id;
    int patient_id;
    Condition *condition_IA;
    int timestamp;
};
```

Condition:
```c
struct condition {
    char *name;
    int gravity;
};
```

XRMachine:
```c
struct xr_machine {
    int id;
    Patient *patient;
    int timestamp;
};
```

Report:
```c
struct report {
    int id;
    int exam_id;
    Condition *condition; 
    int timestamp;
};
```

Existem 5 TADs principais nesse projeto, sendo que 2 deles envolvem decisões de implementação da dupla.

**Patient:** um paciente, possui o seu ID, nome, e o momento da simulação em que chegou ao hospital.

**Exam:** um exame, possuir o seu ID, o ID da máquina que foi usada, o ID do paciente que fez o exame, uma condição, e o momento da simulação em que foi realizado.

**Condition:** uma condição, possui um nome, e uma gravidade.

**XRMachine:** uma máquina de raio-x, possui um ID, o paciente que está a usando, e o momento da simulação em que foi usada.

**Report:** o relatório final do médico, possui um ID, o ID do exame a que se refere, a condição apontada pelo exame, e o momento da simulação em que foi realizado.

### Decisões de implementação:

Dentre eles, 2 TADs foram decisões de implementação, o TAD para a condição do paciente (Condition), e o TAD para uma máquina de raio-x (XRMachine).

O TAD da condição do paciente foi criado, pois existem duas situações em que a mesma ação ocorre, a criação de uma nova condição baseada em um valor aleatório, o que nos fez a tomar essa decisão.
Além dele, o TAD das máquinas de raio-x foi criado para que ficasse mais simples saber quantas máquinas estão sendo utilizadas.

Além dos TADs, uma nova fila foi criada. A fila de máquinas de raio-x (XRMachineManager), o que tornou a verificação de quantas máquinas estão ocupadas trivial.