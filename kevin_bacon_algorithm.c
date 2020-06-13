#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
	
	
	
	/* Onemli Not:  Hocam Merhaba. Input 1 ve 2 cal�s�rken 3 cal�sm�yor. Bunun algoritmayla bir alakas� olmad�g�n�, tamamen size boyutuyla alakal� oldugunu dusunuyorum.
	MAX diye belirttigim degeri 200000 yapt�g�m zaman cal�s�r diye dusunuyordum fakat san�r�m say�n�n cok yuksek olmas� sebebiyle program dahi ac�lmayabiliyor. (Hatta MAX � o kadar yukse secince
	input 1 ve 2 dahi hata verebiliyor). Bu yuzden input3 orneklerini atam�yorum size. Input 1 ve 2 ornegi koymak durumunday�m rapora gorebilmeniz icin c�kt�lar�. */
		
	
	
		struct Queue 
	{ 
	    int front, rear, size; 	// quenun bas�n� sonunu size�n� tutan elemanlar
	    unsigned capacity; 		// queuenun kapasitesi
	    int* array; 			
	}; 



	
	struct node {				// bizim graftaki nodelar�m�z
		char vertexName[150]; 	// aktor veya filmin ad�
		int vertex;				// vertexin numaras�	
		struct node* next; 		// gezebilmemiz icin nextimiz
		};
		
	
	struct Graph { 
		int numVertices; 			// adjLists icin gereken vertex say�m�z
		struct node** adjLists; 	// graf�m�z� olusturmam�zda yard�m eden adjList
		};
	
	
	struct node* createNode(char vertex_name[],int vertexNo) {			//  Node olusturma islemi
		
		
		struct node* newNode= malloc(sizeof(struct node)); 				// yeni node u olusturuyoruz
		
		
		newNode->vertex=vertexNo; 										// vertex say�s�n�, vertex ismini yerlestirip nextini null olarak belirliyoruz
		strcpy(newNode->vertexName,vertex_name);						
		newNode->next = NULL; 
		return newNode; 
		}
	
	
	struct Graph* createGraph(int vertices) { 						// Graf� olusturma
		int i; 														// adjListi NULL lamak icin olusturuyoruz
		struct Graph* graph = malloc(sizeof(struct Graph)); 
		
		graph->numVertices= vertices; 									//vertex number� yerlestirdik
		graph->adjLists= malloc(vertices * sizeof(struct node*));		// adjListe kac verteximiz var ise o kadar yer ac�yoruz
		
		for (i= 0; i< vertices; i++) 
		graph->adjLists[i] = NULL; 								// adjListin ilk �nce NULL poizsyona getiriyoruz
		return graph; 	
		}
	
	
	void addEdge(struct Graph* graph, int src, int dest,char vertexName1[],char vertexName2[]) {		// dugumleri birlestirme
	 struct node* newNode= createNode(vertexName2,dest); 					// birlestirecegimiz nodelardan birini yarat�yoruz
	 newNode->next = graph->adjLists[src]; 									// adjListte baglancag� node a bagl�yoruz
	 graph->adjLists[src] = newNode; 										// baglanacag� adjListe nodeu ekliyoruz		
	 newNode= createNode(vertexName1,src); 									
	 newNode->next = graph->adjLists[dest]; 								// ayn� islemi baglayacag�m�z ikinci dugum icin yap�yoruz
	 graph->adjLists[dest] = newNode; 
	 } 
		
	
		
	
	struct Queue* createQueue(unsigned capacity) 							// queue olusturma kapasite kadar olusturabiliriz
	{ 
	    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 	// queue ya yer ac�yoruz
	    queue->capacity = capacity; 											// kapasitesini belirliyoruz
	    queue->front = queue->size = 0;  										// frontu basa koyuyoruz
	    queue->rear = capacity - 1;  											// enqueue islemi yaparken kontrol etmemiz gerekiyor kapasiteyi rear� kapasitenin bir alt� olarak belirliyoruz
	    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 			// ve queue arrayimizi olusturuyoruz
	    return queue; 
	} 
	
	
		
	int isFull(struct Queue* queue) {								
	  return (queue->size == queue->capacity); 			// queue fullsa 1 degilse 0 donuyoruz
	   } 	
		
		
	
	int isEmpty(struct Queue* queue) {
	  return (queue->size == 0); 					// queue bossa 1 doluysa 0 donduruyoruz
	  } 
	
	
	
	void enqueue(struct Queue* queue, int item) { 
	    if (isFull(queue)) 
	        return; 
	    queue->rear = (queue->rear + 1)%queue->capacity; 
	    queue->array[queue->rear] = item; 
	    queue->size = queue->size + 1; 
	  //  printf("%d enqueued to queue\n", item); 
	} 
	
	
	
	
	int dequeue(struct Queue* queue) 
	{ 
	    if (isEmpty(queue)) 
	        return INT_MIN; 					// eger queue bos ise bisey dondurmemeiz laz�m
	    int item = queue->array[queue->front]; 		// Listenin bas�ndaki eleman� al�yoruz
	    queue->front = (queue->front + 1)%queue->capacity; 			// listenin frontunu bir ilerletiyoruz
	    queue->size = queue->size - 1; 				// size � 1 azalt�yoruz
	    return item; 
	} 
	
	
	
	int front(struct Queue* queue) 			// listenin bas�ndaki eleman� al�p donduruyoruz
	{ 
	    if (isEmpty(queue)) 
	        return INT_MIN; 						
	    return queue->array[queue->front]; 					
	} 
	
	
	int rear(struct Queue* queue) 			// listenin sonundaki eleman� al�p donduruyoruz
	{ 
	    if (isEmpty(queue)) 
	        return INT_MIN; 
	    return queue->array[queue->rear]; 
	} 
		
	
	
	
		
	
	void yazdir (int selected,int count_index,int *count,char yenidegiskenler[MAX][150],char *isim,int * aradigimkb,char parent[MAX][150],int kevin_index){	// yazd�rma fonksiyonu
		
		int i;
		
		if(selected==1){		// eger kullan�c� her kb say�s�ndan kacar adet oldugunu gormek istemisse buraya giriyoruz
		printf("kb sayisi 0 olanlar 1 \n");
		for(i=1;i<=count_index;i++)
			printf("kb sayisi %d olanlar %d \n",i,count[i]);		//count adl� her kb say�s�ndan kacar adet oldugunu tutan listemi yazd�r�yorum
	
	}
	
	char  yazdirma[4][150]; // Hangi oyunucunun , hangi oyuncuyla ayn� filmde oynad�g�n� tutan listem
	
	int k=0;		// birazdan yazdirma dizisinde gezerken kullanacag�m indis
	

	if(selected==2){	// eger kullan�c� Bir aktorun kb a olan uzakl�g�n� ve nas�l iliski kurdugunu istiyorsa buraya giriyoruz
				
		i=0;
		while(strcmp(isim,yenidegiskenler[i])) 				// arat�lan film yada aktorun adresini buluyorum.
				i++;
		
		if(aradigimkb[i]==10000){
			
		printf("%s nin kevin bacon sayisi: sonsuz\n",isim);	
				exit(0);
		}
		
		printf("%s nin kevin bacon sayisi: %d\n",isim,aradigimkb[i]);
		
		strcpy(yazdirma[k],isim); 	// guzel gozukmesi ac�s�ndan burada al�yorum il aktorumu
		k++;
		
		
		
		while(i!=kevin_index){			// kevin bacona ulasana kadar devam ediyorum
			
			if(k==3){		// eger yazd�rma islemi icin haz�rsam giriyorum
				
				printf("%s - %s : %s  \n",yazdirma[0],yazdirma[2], yazdirma[1]);		// hangi aktorun hangi aktorle iliski kurdugu ve hangi filmde oynad�klar�n� yazd�r�yorum
				k=1;																	// tekrar yazd�rma islemi haz�r olana kadar donmek icin k y� 1 yap�yorum
				strcpy(yazdirma[0],yazdirma[2]); 										// son aktorden devam edecegim icin son aktoru 0. indise kopyal�yorum
			}
			strcpy(yazdirma[k],parent[i]);			// yazdirma listesine i. aktor veya filmin olsutugu aktor ya da filmi aktar�yorum
			
			i=0;
			while(strcmp(yazdirma[k],yenidegiskenler[i])) 				// film yada aktorun adresini buluyorum. 
				i++;
			
			k++; 
		
		}	
	
		printf("%s - %s : %s  \n",yazdirma[0],yazdirma[2], yazdirma[1]);	// ne son kevin baconl� sat�r� da yazd�r�yorum

	}		
	}
	
	
	
	
	
	
///////////////////////////////////////////////           MAIN               ///////////////////////////////////////////	
	
	
	

	int main(){
		
		int i=0,j;
		int result,ekleme=0,k,z=0;
		
		char *a;										// tum sat�rlar� strtok ile gezerken / ile ay�rd�g�m elemanlar� tuttugum iki char array
		char *b;
		
		char dosya[30];									// input alacag�m dosyan�n ad�
		char buf[MAX];									// input al�rken kullanacag�m buffer
		char isim[200];									// kullan�c�n�n aramak istedigi isim
		char bos[10];									// gets islemi s�ras�nda olusan hatay� onlemek ad�na yarat�lm�s bir string
		
		char degiskenler[8000][150];					// Tum / ile ayr�lm�� olan elemanlar� tuttugum liste
		int selected;									// Kullan�c�n�n hangi islemi yapmak istedigini anlad�g�m deger 1 ise kb degerlerini yazd�r�r, 2 ise verilen ismin kb olan uzakl�g� gosterilir.
		
		printf("Okumak istediginiz dosyanin adini giriniz: ");
		scanf("%s",&dosya);
		
		printf("Her Kevin bacon sayisindan kacar tane oldugunu gormek icin 1'e\n(Soyad, Ad) formatinda yazilmis kisinin kevin bacon sayisini ogrenmek icin 2'ye basin'");
		scanf("%d",&selected);
		
		if(selected==2){
			gets(bos);												// onceki inputta entera bas�ld�g�nda hata c�kmamas� icin kullan�l�yor
			printf("Ismi giriniz: ");
			gets(isim); 											// kullan�c�n�n kevin baconla mesafesini merak ettigi ismi al�yoruz
			
		}

		
		FILE * ptr;													// ulasacag�m�z dosya icin bir file pointer yarat�yoruz
		FILE * fp;													// daha sonra dosya�n bas�ndan itibaren tekrar gezecegimiz icin 2. f�le pointer� tan�ml�yoruz
		
		ptr=fopen(dosya,"r");										// dosyay� aciyoruz
		
		 
		while(fgets(buf,MAX,ptr)){			// Dosyan�n sonuna kadar devam ediyor ve sat�r sat�r al�yor
			
			a=strtok(buf,"\n");				// Herhangi bir sorun c�kmamas� ac�s�ndan once sat�ra gore ay�r�yorum
			b=strtok(a,"/");				// Ard�ndan elemanlar�m� '/' isaretine gore ay�r�yorum
			while(b!=NULL){					// O sat�r�n sonuna kadar '/' isaretiyle ay�rmaya devam et
				
				strcpy(degiskenler[i],b);		// ald�g�n eleman� degiskenler listesine koy
				b=strtok(NULL,"/");				// bir sonraki elemana gec
				i++;							// degiskenler listesinin sonraki eleman�na gec
			
		}	
	}		
	

	
	char yenidegiskenler[i][150];			// degiskenler listesinde tutulan elemanlar�n baz�lar� 1 den fazla kez listede gectiginden adjLists icin vertex number hesaplanmas� ve daha sonradan
											// isime cok yarayacag� icin her eleman�n birer kez gececegi yenidegiskenler listem. i tane eleman oldugundan bu sekilde boyutunun belirlenmesi yeterli
	
	
	for(j=0;j<i;j++){					// degiskenler listesinin tum elemanlar� geziyorum
		
		strcpy(a,degiskenler[j]);		// eleman�m� bir stringe at�p sonraki elemanlarla karsilastiriyorum tekrar geciyor mu diye
		
		for(k=j+1;k<i;k++){				// karsilastirmaya sonraki elemandan basliyorum
			
			result=strcmp(a,degiskenler[k]);			// listede kendinden sonra bidaha kendisi ge�iyorsa eklemiyor atl�yor 														// ve en sonda kendinden sonra eleman kalmayac�g� icin en son esdeger eleman� listeye koyuyor
		
			if(result==0){
				ekleme=1;								// eleman sonradan da gectigi icin eklememesi gerektigini belirtiyor
				break;
		}			
	}
		
		if(ekleme==0){
			
			strcpy(yenidegiskenler[z],a);			// eger eklenmesinde sorun yoksa sorun yoksa ekliyor ve z yi artt�ryor. Bu z degerimiz ileride cok kullanacag�m�z 
													// yenidegiskenler listemizin boyutunu belirtecek ayn� zamanda vertex sayimiz olacak
			z++;
		}	
		ekleme=0;		// kontrollere devam edebilmek icin resetliyoruz		
	}
		
	int sorunYok=0;			// kelimen�n var olup olmad�g� kontrolu
		
	for(i=0;i<z;i++){
		
		if(!strcmp(isim,yenidegiskenler[i]))		// kelime listede varsa sorunYok 1 oluyor
			sorunYok=1;
			
	}	
	if(selected==2){
		if(sorunYok==0){
		printf("Kelime listede yok");		// kelime listede yoksa bitiyor
		exit(0);
	}
	}
	
	
	struct Graph * graph;			
	graph=createGraph(z);		// z vertex say�m�z oldugundan adjListsimizin de boyutu olacak. adjList olustu
	

	/////////////////// AD EDGE /////////////////
	
	
	fp=fopen(dosya,"r");  		// dosyay� tekrar bastan itibaren gezmem gerektigi icin tekrar ac�yorum

	int movie_index;		// filmin adresi
	struct node* newNode;	// yeni node referans�
	char movie[100];	// film ad�n� tutmak icin
	char actor[50];		// actor ad�n� tutmak icin
	char *d;			// her sat�r� tutmak icin gereken string
	char *e;			// her sat�rda bulunan '/' ile ayr�lan elemanlar� tutmak icin gereken string
	
	
	while(fgets(buf,MAX,fp)){	// dosyan�n sonuna kadar devam et		
					
			d=strtok(buf,"\n");		// sat�r� d ye al
			e=strtok(d,"/");		//  	'/' ile ayr�lm�s elemanlar� e ye al
			strcpy(movie,e);		// filmin ad�n� kopyala			
		
			j=0;
			while(strcmp(movie,yenidegiskenler[j]))		// filmin indexini bul
			j++;
		
			movie_index=j;
				
			e=strtok(NULL,"/");					// aktorlere gec
		
			while(e!=NULL){		// ayn� sat�rdaki yani o filmin aktorleri bitene kadar
					
				i=0;
				while(strcmp(e,yenidegiskenler[i]))			// aktorler�n indisini bul 
				i++;
			
				addEdge(graph,movie_index,i,movie,e);		// aktor ile film aras�ndaki edge i olustur yani graph olusuyor
				
				e=strtok(NULL,"/");
		}		
	}		
	
 	
 		

	////////////////////////BFS BA�LANGICI //////////////////////////////////////////
	
		
	int kevin_index; 	// kevin baconun bulundugu adres
	
	char kevin[12]={'B','a','c','o','n',',',' ','K','e','v','i','n'}; 	// kevin baconu kevin isimli chara atad�m
		

	i=z;		// i yi son elemandan baslatt�m	
	while(strcmp(kevin,yenidegiskenler[i]))		// �ndende ba�latabilirdim ama en son kevin baconu bulacag� icin daha k�sa surer
				i--;

	kevin_index=i;		//k evin baconun adresi belirlendi
		
	int visited[z];		// queue da kullanac�g�m o eleman daha once ziyaret edildimi kontrolu �c�n visited dizimi olusturdum
	
	for(i=0;i<z;i++)		
		visited[i]=0;		// her indexin visited�n� 0 yapt�m bu gezilmedi anlam�na geliyor
	
	
	int kb_sayisi=0;		//kb say�s�n� belirleycek olan degisken
	int count[100];			// her kb sayisindan kacar tane var belirleyen degisken
	
	for(i=0;i<100;i++)		
		count[i]=0;			// tum kb say�lar�ndan basta 0 tane var
	
		
	int count_index=0;			// kb ad�mlar�nda kullan�lacak olan countun indexini degistirecek olan degisken
	struct node* temp;
	int v,exclamationCheck=1;			// Bu degisken 1 ise bir film var elimizde , 0 ise bir aktor var elimizde .
										// en son filmde miydi akt�rde miydi onu belirtiyor, filmden akt�re ge�ince kb_sayisi art�yor
	
	struct Queue* queue = createQueue(z);		// queue yu eleman say�m olan z ye gore olusturdum
	
	char kelime[150];										// birazdan queue icinde bfs yaparken ortaya c�kan film ve oyuncu isimlerini bir sure saklayacag�m string
	enqueue(queue,kevin_index);								// En ba�ta kevin bacon� queue ya at�yorum
	visited[kevin_index]=1;									// kevin baconu visited olarak isaretliyorum
	
	char kontrol_kelime[100];								// birazdan al�nan bir eleman�n bir film mi yoksa bir aktor mu belirlenmesi icin kullan�lacak string
	int	aradigimkb[z];										// her aktorun kb say�s�n� kendi inidisyle bulacag�m�z liste
	
	
	for(i=0;i<z;i++)
		aradigimkb[i]=10000;								// oncelikle tum aktorler�n kb_sayisini 10000 yap�yorum

	char parent[z][150];									// bfs s�ras�nda olusan degiskenin kim taraf�ndan olusturuldugunu gosteren liste
			

	// queue islemlerinin baslad�g� yer
	
	while(!isEmpty(queue)){								// queue bos kalana kadar devam et
		
		v=dequeue(queue);								// queuenun ba��n� c�kar komuslar�n� gezmeye basla
			
		temp = graph->adjLists[v];						// c�kart�g�n vertex nolu adjliste git, buradan komsular� queue ya atacag�z
						
		strcpy(kontrol_kelime,graph->adjLists[v]->vertexName);		//  dequeue ettigim kelimeyi kontrol etmek icin kontrol_kelime de sakl�yorum

	
			// kevin bacon sayisi bulma islemi burada gerceklesiyor
	
		if(exclamationCheck==1){			// eger exclamationCheck==1 ise bu kelimeden once dequeue ettigimiz kelime bir filmmis anlam�na geliyor
			 
			 
		  if(strchr(kontrol_kelime, '(') != NULL)  {		// suan yeni dequeue ettigimiz kelimede filmse ife giriyor.	'(' i�eriyor mu yani film mi dizi mi?
		    exclamationCheck = 1; 					// film olarak isaretliyoruz
		  }
		  
		  else{														// eger bu kelimeden onceki deger filmse ve simdi aktore gecilmisse
		  	kb_sayisi++;											// kb_sayisi ni artt�r�yorum count indextte kb sayisinin degerini saklad�g� icin art�yor
		  	count_index++;					
		  	exclamationCheck=0;										// en son dequeue edilenin bir aktor oldugunu isaretliyorum
	
		  }		
		}
		
		else{								// eger onceki kelime aktorse sadece yeni kelime film mi kontrolu yap�p filmse degeri guncelliyorum
			
			if(strchr(kontrol_kelime, '(') != NULL) {
		    exclamationCheck = 1; 							// ( i�eriyor mu yani film m i dizi mi?
		  }			
		}
	   

		while (temp) {		// dequeue ettigim degerin tum komsular�n� burada geziyorum
				
		strcpy(kelime,temp->vertexName);		// yeni degeri kelimeye kopyal�yorum
		
		i=0;
		while(strcmp(kelime,yenidegiskenler[i])) 				// film yada aktorun adresini buluyorum.
				i++;
				
		if(visited[i]==0){							// eger daha once gezilmediyse bu aktor veya filmi queue ya at�yorum gezildiyse atm�yorum
		
			enqueue(queue,i);		
			
			
			if(exclamationCheck==0){	//eger bu bir aktorse
				count[count_index]++;		// kb say�s�ndaki aktor miktar�n� artt�r�yorum
							
				aradigimkb[i]=kb_sayisi;	// ve bu aktorun kb say�s�n� yerlestiriyorum								
			}
						
			strcpy(parent[i],yenidegiskenler[v]);	// olusan aktor veya filmin hangi aktor veya filmden olsutugunu parent listesine yerlestiriyorum
			visited[i]=1;		      				// ve gezildi olarak isaretliyorum
		}		
		
	      temp = temp->next;						// sonraki komsuya geciyorum
	    }	
	}

	
		yazdir(selected,count_index,count,yenidegiskenler,isim,aradigimkb,parent,kevin_index);		// yazdirma islemi
	

		return 0;
	}
	
	
	
	
