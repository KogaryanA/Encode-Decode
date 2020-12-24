#include "stringutils.h"
#include "coder.h"

int main(int argc, char* argv[]) {
    
    if (argc == 1){
        char coder[6];
        printf("Enter Caesar or XOR: ");
        scanf("%s", coder);
        printf("\n");

        char text[200];
        printf("Enter text: ");
        scanf("%s", text);
        printf("\n");

        if (whatCoder(coder, "Caesar") == 0) {
            int offset;
            printf("Enter offset: ");
            scanf("%d", &offset);
            printf("\n");
            printf("%s\n", immutableCaesarDecoder(text, offset));
        }

        else if (whatCoder(coder, "XOR") == 0) {
            char password[200];
            printf("Enter password: ");
            scanf("%s", password);
            printf("\n");
            printf("%s\n", immutableXorCoder(text, password));
        }

        else {
            printf("Error\n");
        }

        return 0;
        
    } else if (argc == 4) {
        
        if (whatCoder(argv[1], "--caesar") == 0) {
            int offset = atoi(argv[3]);
            printf("%s\n", immutableCaesarDecoder(argv[2], offset));
        }

        else if (whatCoder(argv[1], "--xor") == 0) {
            printf("%s\n", immutableXorCoder(argv[2], argv[3]));
        }

        else {
            printf("Error\n");
        }
    } else {
        printf("Error\n");
    }
}
