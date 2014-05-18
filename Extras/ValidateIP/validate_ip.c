#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool valid_byte(char* byte)
{
        // 01.100.100.100 iro haagilla :(
        if(byte[0] = '0'){
                return false;
        }
        while(*byte){
                if(isdigit(*byte)){
                        ++byte;
                }
                else{
                        return false;
                }
        }
        return true;
}

bool isValidIP(char* ip_address)
{
        int seperator = 0;
        if(ip_address == NULL){
                return false;
        }
        else{
                //printf("here\n");
                char *eachByte;
                eachByte = strtok(ip_address,".");
                //printf("Eachbyte is\n");
                if(eachByte == NULL){
                        return false;
                }
                while(eachByte)
                {       
                        //Ayyo devre idakondu function bari beka :P
                        // pthuu python! :D
                        if(!valid_byte(eachByte)){
                                return false;
                        }
                        int value = atoi(eachByte);
                        if(value < 0 && value > 255){
                                return false;
                        }
                        printf("Here\n");
                        eachByte = strtok(NULL,".");
                        //printf("Here\n")
                        if(eachByte){
                                ++seperator;
                        }
                        
                }
               // printf("\n");
        }
       if(seperator != 3){
                return false;
       }
        return true;
}

int main()
{
        char ip_address[16];
        printf("Enter the IP address u want to validate\n");
        gets(ip_address);
        //printf("Here\n");
        if(isValidIP(ip_address)){
                printf("valid ipv4 address!\n");
        }
        else{
                printf("invalid ipv4 address!\n");
        }

        return 0;
}
