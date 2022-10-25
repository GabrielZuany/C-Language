typedef struct usuario Usuario;

Usuario* CriaUsuario(char* nome, int cpf);

char* RecuperaNomeUsuario(Usuario* usuario);

int RecuperaCpfUsuario(Usuario* usuario);

void DestroiUsuario(Usuario* usuario);