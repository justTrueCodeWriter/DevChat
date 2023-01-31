#include <stdio.h>
#include <string>

void user_login(char *username);
void user_message(char *username, char *message);
void user_message_to_file(char *username, char *message);


int main() {

	char username[20];
	char message[300];
	char messageToTextFile[323];
	user_login(username);
	while (true) {
		user_message(username, message);
		user_message_to_file(username, message);
	}
	//printf("%s", username);
	
}

void user_login(char *username) {
	scanf("%s", username);
}

void user_message(char *username, char *message) {
	printf("[%s]: ", username); scanf("%s", message);
}

void user_message_to_file(char *username, char *message) {
	FILE *fp;

	fp = fopen("chat", "a");
	fprintf(fp, "[%s]: %s\n", username, message);
	fclose(fp);

}
