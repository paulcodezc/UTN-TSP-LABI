//Prototipos

int esNumerico(char str[]);

int esAlfaNumerico(char str[]);

int esSoloLetras(char str[]);

int esEntero(char str[]);

int validarFlotante(char lista[]);

int contarCaracteres(char campo[], int tamano);

int getFecha(int* inputD, int* inputM, int* inputA, char messageD[], char messageM[], char messageA[]);

int funChequeoNumero(char num[]);

int esCaracter (char letra);

int getStringV(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

int getStringAlfanumericoV(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

int getIntV(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

int getFloatV(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

int getFlotanteV(char *input, char *message);

int getCharV(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

int getSN(char* input, char message[], char eMessage[]);

int getIDV(LinkedList* pArrayListEmployee, char *mensaje);

int getHorasTrabajadasV(LinkedList* pArrayListEmployee, char *mensaje);

int getUnoCero(int* input, char message[]);

void wait();
