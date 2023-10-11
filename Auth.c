
#include <stdio.h>
#include <string.h>

#define MAX_USERS 30
#define MAX_USERNAME_LENGTH 10
#define MAX_PASSWORD_LENGTH 10

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS]; 
int userCount = 0; 
 

void RegisterUserDeligate() {
    if (userCount < MAX_USERS) {
        struct User newUser;

        printf("Enter a username please : ");
        scanf("%s", newUser.username);

        printf("Enter a password please : ");
        scanf("%s", newUser.password);

        users[userCount++] = newUser;
        printf("Registration successful!\n");
    } else {
        printf("User limit reached. Cannot register more users.\n");
    }
}


int loginUserDeligate(const char *username, const char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int Mychoice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("\n1. Register\n2. Login\nEnter your choice: ");
        scanf("%d", &Mychoice);

        switch (Mychoice) {
            case 1:
                RegisterUserDeligate();
                break;

            case 2:
                printf("Enter your username: ");
                scanf("%s", username);

                printf("Enter your password: ");
                scanf("%s", password);

                if (loginUserDeligate(username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
