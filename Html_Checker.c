/************ copyright(c) ftastemur 2011 HTML TAG CHECKER ***********/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************* Stack *************************************/

struct tags {
	char *tag;
	struct tags *next;
};

typedef struct tags tags;

tags *etiket = NULL;	// etiketler burda
char kaynak[100];		// dosyadan okunanlar burda

void
push(char *data)	// push
{
	tags *new;

	new = (tags *)malloc(sizeof(tags));
	if (new == NULL) {
		fprintf(stderr,"Yeterli hafıza yoktur.");
		exit(EXIT_FAILURE);
	}
	// "etiket"e bastan ekleme islemi
	new->tag = strdup(data);	// tag degiskenine direk atama yapilamaz bu yuzden strdup kullanilir
	new->next = etiket;
	etiket = new;
}

void
pop(void)			// pop()
{
	tags *current;
	current = etiket;
	etiket = etiket->next;
	free(current);
	
}

int
isEmpty(void)			// isEmpty
{
	return (etiket != NULL);	
}

/************************* read file *********************************/

void
read(void)				// dosyadaki bilgiler "kaynak" dizisine aktarilir
{
	FILE *fp;
	int i = 0;
	if ((fp = fopen("index.htm", "r")) == NULL) {
		fprintf(stderr,"index.htm isimli dosya yok..\n");
		exit(EXIT_FAILURE);
	}
	
	do {
		fscanf(fp, "%c", &kaynak[i++]);
	} while (!feof(fp));		
	kaynak[i] = '\0';
	
	
	
	fclose(fp);
}

/*********************** Checker ***********************************/

void
checker(void)			// taglarin kontrol edildigi yer 
{
	int j, i = 0;
	char tag_tur[10];	// etiketi tutmak icin
	for (i = 0; kaynak[i] != '\0'; i++){
	
		if (kaynak[i] == '<') {
			if (kaynak[i + 1] != '/') {		// acma etiketi geldiyse
				j = 0;
				i++;
				while(kaynak[i] != '>')		// etiketi bulma
					tag_tur[j++] = kaynak[i++];

				tag_tur[j] = '\0';
				push(tag_tur);		// etiketi "etiket" degiskenine ekleme
				
			} // if
			
			if (kaynak[i + 1] == '/') {		// kapama etiketi geldiyse
				if(!isEmpty()) {			// stack bossa ve kapama geldiyse
					printf("HTML Dengesizdir..!!!\n");
					return;
				}
				j = 0;
				i += 2;
				while(kaynak[i] != '>')		// etiketi bulma
					tag_tur[j++] = kaynak[i++];
					
				tag_tur[j] = '\0';
				if(strcmp(tag_tur, etiket->tag) != 0) {		// farkli acma kapama varsa
					printf("HTML Dengesizdir..!!!\n");
					return;
				} //if
				pop();		
					
			} //if	
			
		}// if
			
	}// for
	if(isEmpty())
		printf("HTML Dengesizdir..!!!\n");	// kontrol bitmesine ragmen "etiket" bos degilse
	else
		printf("HTML Dengelidir..\n");	// "etiket" bossa
		
}

void
destroy(void)		// free
{
	tags *current, *yedek;
	current = etiket;
	while (current) {
		yedek = current->next;
		free(current);
		current = yedek;
	}
}

/************************** main ************************************/

int
main()
{
	read (); 
	checker ();	
	destroy();
	
	return 0;
}

/********************************************************************/
