#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *PCL(char *s1, char *s2, char **pcl);
int min(int n1, int n2);

int main(int argc, char *argv[]){
	if(argc<3){
		fprintf(stderr, "Please provide a valid number of arguments: ./<file_name> <string> <string>\n");
		exit(1);
	}

	char *pcl;
	printf("%s\n", PCL(argv[1], argv[2], &pcl));
	return 0;
}

char *PCL(char *s1, char *s2, char **pcl){
	int len = min(strlen(s1), strlen(s2));
	(*pcl) = malloc(len);
	for(int i=0; i<len; i++){
		if(s1[i] == s2[i]){
			(*pcl)[i] = s1[i];
		}
		else{
			break;
		}
	}
	return *pcl;
}

int min(int n1, int n2){
	return n1>n2 ? n2 : n1;
}
