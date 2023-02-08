#include <stdio.h>
#include <string>

void user_login(char *username);
int user_message(char *username, char *message);
void user_message_to_file(char *username, char *message);
void system_message(char *username, char *message);


int main() {

	char username[20];
	char message[300];
	char messageToTextFile[323];
	int systemMessage;
	user_login(username);
	while (true) {
		systemMessage = user_message(username, message);
		if (systemMessage == -1) 
			return 0;
		user_message_to_file(username, message);
	}
	//printf("%s", username);
	
}

void user_login(char *username) {
	char sys[] = "joined chat";
	printf("login: "); scanf("%s", username);
	system_message(username, sys);
}

int user_message(char *username, char *message) {
	printf("[%s]: ", username); scanf("%s", message);
	char sys[] = "left chat";
	if (message[0] == 'q') {
		system_message(username, sys);
		return -1;		
	}
	return 0;
}

void user_message_to_file(char *username, char *message) {
	FILE *fp;

	fp = fopen("chat", "a");
	fprintf(fp, "[%s]: %s\n", username, message);
	fclose(fp);

}

void system_message(char *username, char *message) {

	FILE *fp;

	fp = fopen("chat", "a");
	fprintf(fp, "SYSTEM: [%s] %s\n", username, message);
	fclose(fp);

}
