// 编写一外部命令mydir，该命令列出指定目录下的目录列表，并统计文件数与目录数。

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]){
	char const*path = argv[1];
	struct stat s_buf;

	stat(path,&s_buf);

 	int dir_num = 0;
  int file_num = 0;
	if(S_ISDIR(s_buf.st_mode)) {
		printf("%s it is a dir\n",path);
		struct dirent *filename;
		DIR *dirp = opendir(path);

		while((filename = readdir(dirp)) != NULL) {
			char file_path[100];
			bzero(file_path,100);
			strcat(file_path,path);
			strcat(file_path,"/");
			strcat(file_path,filename->d_name);
			
			stat(file_path,&s_buf);

			if (S_ISDIR(s_buf.st_mode)) {
				printf("%s is a dir\n",file_path);
        dir_num++;
			}

			if(S_ISREG(s_buf.st_mode)) {
        file_num++;
			}
		}
    printf("there is %d directories:\n", dir_num);
    printf("there is %d files:\n", file_num);
    closedir(dirp);
    exit(0);
	} else if(S_ISREG(s_buf.st_mode)) {
		printf("%s is a regular file\n",path);
		exit(1);
	}

	return 0;
}