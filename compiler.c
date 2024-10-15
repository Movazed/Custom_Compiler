#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef enum{ 
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
} TypeSeperator;

typedef enum{
    EXIT,
} TypeKeyword;

typedef enum{
    INT,
} TypeLiteral;

typedef struct{
   TypeKeyword type;
} TokenKeyword;

typedef struct { 
    TypeSeperator type;
} TokenSeperator;

typedef struct { 
    TypeLiteral type;
    char* value;
} TokenLiteral;

TokenLiteral *generate_number(char current, FILE *file){
    TokenLiteral *token;
    token->type = INT;
    char *value = malloc(sizeof(char) * 8);
    int value_index = 0; 
    while (isdigit(current) && current != EOF)
    {   if(!isdigit(current)){
        break;
    }   
    value[value_index] = current;
    value_index++;
    printf("%c", current);
    current = fgetc(file);
    }
    token->value = value;
    free(value);
    return(*token);
}

void lexer(FILE *file){ 
    char current = fgetc(file); 

    while(current != EOF){   
        if(current == ';'){ 
            printf("FOUND SEMICOLON\n");
        } else if(current == '('){
            printf("FOUND OPEN PAREN\n");
        } else if(current == ')'){
            printf("FOUND CLOSE PAREN\n");
        }  else if(isdigit(current)){
            TokenLiteral *test_token = generate_number(current, file);
            printf("TEST TOKEN VALUE: %s\n", test_token->value);

            // printf("FOUND DIGIT: %d\n", current - '0');
        } else if(isalpha(current)){
            printf("FOUND CHARACTER: %c\n", current);
        }
        current = fgetc(file);  
    }
}

int main() { 
    FILE *file;
    file = fopen("test.unn", "r"); 
    lexer(file);
}

