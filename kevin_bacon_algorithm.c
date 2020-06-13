#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
	
	
	
	/* Onemli Not:  Hocam Merhaba. Input 1 ve 2 calýsýrken 3 calýsmýyor. Bunun algoritmayla bir alakasý olmadýgýný, tamamen size boyutuyla alakalý oldugunu dusunuyorum.
	MAX diye belirttigim degeri 200000 yaptýgým zaman calýsýr diye dusunuyordum fakat sanýrým sayýnýn cok yuksek olmasý sebebiyle program dahi acýlmayabiliyor. (Hatta MAX ý o kadar yukse secince
	input 1 ve 2 dahi hata verebiliyor). Bu yuzden input3 orneklerini atamýyorum size. Input 1 ve 2 ornegi koymak durumundayým rapora gorebilmeniz icin cýktýlarý. */
		
	
	
		struct Queue 
	{ 
	    int front, rear, size; 	// quenun basýný sonunu sizeýný tutan elemanlar
	    unsigned capacity; 		// queuenun kapasitesi
	    int* array; 			
	}; 



	
	struct node {				// bizim graftaki nodelarýmýz
		char vertexName[150]; 	// aktor veya filmin adý
		int vertex;				// vertexin numarasý	
		struct node* next; 		// gezebilmemiz icin nextimiz
		};
		
	
	struct Graph { 
		int numVertices; 			// adjLists icin gereken vertex sayýmýz
		struct node** adjLists; 	// grafýmýzý olusturmamýzda yardým eden adjList
		};
	
	
	struct node* createNode(char vertex_name[],int vertexNo) {			//  Node olusturma islemi
		
		
		struct node* newNode= malloc(sizeof(struct node)); 				// yeni node u olusturuyoruz
		
		
		newNode->vertex=vertexNo; 										// vertex sayýsýný, vertex ismini yerlestirip nextini null olarak belirliyoruz
		strcpy(newNode->vertexName,vertex_name);						
		newNode->next = NULL; 
		return newNode; 
		}
	
	
	struct Graph* createGraph(int vertices) { 						// Grafý olusturma
		int i; 														// adjListi NULL lamak icin olusturuyoruz
		struct Graph* graph = malloc(sizeof(struct Graph)); 
		
		graph->numVertices= vertices; 									//vertex numberý yerlestirdik
		graph->adjLists= malloc(vertices * sizeof(struct node*));		// adjListe kac verteximiz var ise o kadar yer acýyoruz
		
		for (i= 0; i< vertices; i++) 
		graph->adjLists[i] = NULL; 								// adjListin ilk önce NULL poizsyona getiriyoruz
		return graph; 	
		}
	
	
	void addEdge(struct Graph* graph, int src, int dest,char vertexName1[],char vertexName2[]) {		// dugumleri birlestirme
	 struct node* newNode= createNode(vertexName2,dest); 					// birlestirecegimiz nodelardan birini yaratýyoruz
	 newNode->next = graph->adjLists[src]; 									// adjListte baglancagý node a baglýyoruz
	 graph->adjLists[src] = newNode; 										// baglanacagý adjListe nodeu ekliyoruz		
	 newNode= createNode(vertexName1,src); 									
	 newNode->next = graph->adjLists[dest]; 								// ayný islemi baglayacagýmýz ikinci dugum icin yapýyoruz
	 graph->adjLists[dest] = newNode; 
	 } 
		
	
		
	
	struct Queue* createQueue(unsigned capacity) 							// queue olusturma kapasite kadar olusturabiliriz
	{ 
	    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 	// queue ya yer acýyoruz
	    queue->capacity = capacity; 											// kapasitesini belirliyoruz
	    queue->front = queue->size = 0;  										// frontu basa koyuyoruz
	    queue->rear = capacity - 1;  											// enqueue islemi yaparken kontrol etmemiz gerekiyor kapasiteyi rearý kapasitenin bir altý olarak belirliyoruz
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
	        return INT_MIN; 					// eger queue bos ise bisey dondurmemeiz lazým
	    int item = queue->array[queue->front]; 		// Listenin basýndaki elemaný alýyoruz
	    queue->front = (queue->front + 1)%queue->capacity; 			// listenin frontunu bir ilerletiyoruz
	    queue->size = queue->size - 1; 				// size ý 1 azaltýyoruz
	    return item; 
	} 
	
	
	
	int front(struct Queue* queue) 			// listenin basýndaki elemaný alýp donduruyoruz
	{ 
	    if (isEmpty(queue)) 
	        return INT_MIN; 						
	    return queue->array[queue->front]; 					
	} 
	
	
	int rear(struct Queue* queue) 			// listenin sonundaki elemaný alýp donduruyoruz
	{ 
	    if (isEmpty(queue)) 
	        return INT_MIN; 
	    return queue->array[queue->rear]; 
	} 
		
	
	
	
		
	
	void yazdir (int selected,int count_index,int *count,char yenidegiskenler[MAX][150],char *isim,int * aradigimkb,char parent[MAX][150],int kevin_index){	// yazdýrma fonksiyonu
		
		int i;
		
		if(selected==1){		// eger kullanýcý her kb sayýsýndan kacar adet oldugunu gormek istemisse buraya giriyoruz
		printf("kb sayisi 0 olanlar 1 \n");
		for(i=1;i<=count_index;i++)
			printf("kb sayisi %d olanlar %d \n",i,count[i]);		//count adlý her kb sayýsýndan kacar adet oldugunu tutan listemi yazdýrýyorum
	
	}
	
	char  yazdirma[4][150]; // Hangi oyunucunun , hangi oyuncuyla ayný filmde oynadýgýný tutan listem
	
	int k=0;		// birazdan yazdirma dizisinde gezerken kullanacagým indis
	

	if(selected==2){	// eger kullanýcý Bir aktorun kb a olan uzaklýgýný ve nasýl iliski kurdugunu istiyorsa buraya giriyoruz
				
		i=0;
		while(strcmp(isim,yenidegiskenler[i])) 				// aratýlan film yada aktorun adresini buluyorum.
				i++;
		
		if(aradigimkb[i]==10000){
			
		printf("%s nin kevin bacon sayisi: sonsuz\n",isim);	
				exit(0);
		}
		
		printf("%s nin kevin bacon sayisi: %d\n",isim,aradigimkb[i]);
		
		strcpy(yazdirma[k],isim); 	// guzel gozukmesi acýsýndan burada alýyorum il aktorumu
		k++;
		
		
		
		while(i!=kevin_index){			// kevin bacona ulasana kadar devam ediyorum
			
			if(k==3){		// eger yazdýrma islemi icin hazýrsam giriyorum
				
				printf("%s - %s : %s  \n",yazdirma[0],yazdirma[2], yazdirma[1]);		// hangi aktorun hangi aktorle iliski kurdugu ve hangi filmde oynadýklarýný yazdýrýyorum
				k=1;																	// tekrar yazdýrma islemi hazýr olana kadar donmek icin k yý 1 yapýyorum
				strcpy(yazdirma[0],yazdirma[2]); 										// son aktorden devam edecegim icin son aktoru 0. indise kopyalýyorum
			}
			strcpy(yazdirma[k],parent[i]);			// yazdirma listesine i. aktor veya filmin olsutugu aktor ya da filmi aktarýyorum
			
			i=0;
			while(strcmp(yazdirma[k],yenidegiskenler[i])) 				// film yada aktorun adresini buluyorum. 
				i++;
			
			k++; 
		
		}	
	
		printf("%s - %s : %s  \n",yazdirma[0],yazdirma[2], yazdirma[1]);	// ne son kevin baconlý satýrý da yazdýrýyorum

	}		
	}
	
	
	
	
	
	
///////////////////////////////////////////////           MAIN               ///////////////////////////////////////////	
	
	
	

	int main(){
		
		int i=0,j;
		int result,ekleme=0,k,z=0;
		
		char *a;										// tum satýrlarý strtok ile gezerken / ile ayýrdýgým elemanlarý tuttugum iki char array
		char *b;
		
		char dosya[30];									// input alacagým dosyanýn adý
		char buf[MAX];									// input alýrken kullanacagým buffer
		char isim[200];									// kullanýcýnýn aramak istedigi isim
		char bos[10];									// gets islemi sýrasýnda olusan hatayý onlemek adýna yaratýlmýs bir string
		
		char degiskenler[8000][150];					// Tum / ile ayrýlmýþ olan elemanlarý tuttugum liste
		int selected;									// Kullanýcýnýn hangi islemi yapmak istedigini anladýgým deger 1 ise kb degerlerini yazdýrýr, 2 ise verilen ismin kb olan uzaklýgý gosterilir.
		
		printf("Okumak istediginiz dosyanin adini giriniz: ");
		scanf("%s",&dosya);
		
		printf("Her Kevin bacon sayisindan kacar tane oldugunu gormek icin 1'e\n(Soyad, Ad) formatinda yazilmis kisinin kevin bacon sayisini ogrenmek icin 2'ye basin'");
		scanf("%d",&selected);
		
		if(selected==2){
			gets(bos);												// onceki inputta entera basýldýgýnda hata cýkmamasý icin kullanýlýyor
			printf("Ismi giriniz: ");
			gets(isim); 											// kullanýcýnýn kevin baconla mesafesini merak ettigi ismi alýyoruz
			
		}

		
		FILE * ptr;													// ulasacagýmýz dosya icin bir file pointer yaratýyoruz
		FILE * fp;													// daha sonra dosyaýn basýndan itibaren tekrar gezecegimiz icin 2. fýle pointerý tanýmlýyoruz
		
		ptr=fopen(dosya,"r");										// dosyayý aciyoruz
		
		 
		while(fgets(buf,MAX,ptr)){			// Dosyanýn sonuna kadar devam ediyor ve satýr satýr alýyor
			
			a=strtok(buf,"\n");				// Herhangi bir sorun cýkmamasý acýsýndan once satýra gore ayýrýyorum
			b=strtok(a,"/");				// Ardýndan elemanlarýmý '/' isaretine gore ayýrýyorum
			while(b!=NULL){					// O satýrýn sonuna kadar '/' isaretiyle ayýrmaya devam et
				
				strcpy(degiskenler[i],b);		// aldýgýn elemaný degiskenler listesine koy
				b=strtok(NULL,"/");				// bir sonraki elemana gec
				i++;							// degiskenler listesinin sonraki elemanýna gec
			
		}	
	}		
	

	
	char yenidegiskenler[i][150];			// degiskenler listesinde tutulan elemanlarýn bazýlarý 1 den fazla kez listede gectiginden adjLists icin vertex number hesaplanmasý ve daha sonradan
											// isime cok yarayacagý icin her elemanýn birer kez gececegi yenidegiskenler listem. i tane eleman oldugundan bu sekilde boyutunun belirlenmesi yeterli
	
	
	for(j=0;j<i;j++){					// degiskenler listesinin tum elemanlarý geziyorum
		
		strcpy(a,degiskenler[j]);		// elemanýmý bir stringe atýp sonraki elemanlarla karsilastiriyorum tekrar geciyor mu diye
		
		for(k=j+1;k<i;k++){				// karsilastirmaya sonraki elemandan basliyorum
			
			result=strcmp(a,degiskenler[k]);			// listede kendinden sonra bidaha kendisi geçiyorsa eklemiyor atlýyor 														// ve en sonda kendinden sonra eleman kalmayacýgý icin en son esdeger elemaný listeye koyuyor
		
			if(result==0){
				ekleme=1;								// eleman sonradan da gectigi icin eklememesi gerektigini belirtiyor
				break;
		}			
	}
		
		if(ekleme==0){
			
			strcpy(yenidegiskenler[z],a);			// eger eklenmesinde sorun yoksa sorun yoksa ekliyor ve z yi arttýryor. Bu z degerimiz ileride cok kullanacagýmýz 
													// yenidegiskenler listemizin boyutunu belirtecek ayný zamanda vertex sayimiz olacak
			z++;
		}	
		ekleme=0;		// kontrollere devam edebilmek icin resetliyoruz		
	}
		
	int sorunYok=0;			// kelimenýn var olup olmadýgý kontrolu
		
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
	graph=createGraph(z);		// z vertex sayýmýz oldugundan adjListsimizin de boyutu olacak. adjList olustu
	

	/////////////////// AD EDGE /////////////////
	
	
	fp=fopen(dosya,"r");  		// dosyayý tekrar bastan itibaren gezmem gerektigi icin tekrar acýyorum

	int movie_index;		// filmin adresi
	struct node* newNode;	// yeni node referansý
	char movie[100];	// film adýný tutmak icin
	char actor[50];		// actor adýný tutmak icin
	char *d;			// her satýrý tutmak icin gereken string
	char *e;			// her satýrda bulunan '/' ile ayrýlan elemanlarý tutmak icin gereken string
	
	
	while(fgets(buf,MAX,fp)){	// dosyanýn sonuna kadar devam et		
					
			d=strtok(buf,"\n");		// satýrý d ye al
			e=strtok(d,"/");		//  	'/' ile ayrýlmýs elemanlarý e ye al
			strcpy(movie,e);		// filmin adýný kopyala			
		
			j=0;
			while(strcmp(movie,yenidegiskenler[j]))		// filmin indexini bul
			j++;
		
			movie_index=j;
				
			e=strtok(NULL,"/");					// aktorlere gec
		
			while(e!=NULL){		// ayný satýrdaki yani o filmin aktorleri bitene kadar
					
				i=0;
				while(strcmp(e,yenidegiskenler[i]))			// aktorlerýn indisini bul 
				i++;
			
				addEdge(graph,movie_index,i,movie,e);		// aktor ile film arasýndaki edge i olustur yani graph olusuyor
				
				e=strtok(NULL,"/");
		}		
	}		
	
 	
 		

	////////////////////////BFS BAÞLANGICI //////////////////////////////////////////
	
		
	int kevin_index; 	// kevin baconun bulundugu adres
	
	char kevin[12]={'B','a','c','o','n',',',' ','K','e','v','i','n'}; 	// kevin baconu kevin isimli chara atadým
		

	i=z;		// i yi son elemandan baslattým	
	while(strcmp(kevin,yenidegiskenler[i]))		// öndende baþlatabilirdim ama en son kevin baconu bulacagý icin daha kýsa surer
				i--;

	kevin_index=i;		//k evin baconun adresi belirlendi
		
	int visited[z];		// queue da kullanacýgým o eleman daha once ziyaret edildimi kontrolu ýcýn visited dizimi olusturdum
	
	for(i=0;i<z;i++)		
		visited[i]=0;		// her indexin visitedýný 0 yaptým bu gezilmedi anlamýna geliyor
	
	
	int kb_sayisi=0;		//kb sayýsýný belirleycek olan degisken
	int count[100];			// her kb sayisindan kacar tane var belirleyen degisken
	
	for(i=0;i<100;i++)		
		count[i]=0;			// tum kb sayýlarýndan basta 0 tane var
	
		
	int count_index=0;			// kb adýmlarýnda kullanýlacak olan countun indexini degistirecek olan degisken
	struct node* temp;
	int v,exclamationCheck=1;			// Bu degisken 1 ise bir film var elimizde , 0 ise bir aktor var elimizde .
										// en son filmde miydi aktörde miydi onu belirtiyor, filmden aktöre geçince kb_sayisi artýyor
	
	struct Queue* queue = createQueue(z);		// queue yu eleman sayým olan z ye gore olusturdum
	
	char kelime[150];										// birazdan queue icinde bfs yaparken ortaya cýkan film ve oyuncu isimlerini bir sure saklayacagým string
	enqueue(queue,kevin_index);								// En baþta kevin baconý queue ya atýyorum
	visited[kevin_index]=1;									// kevin baconu visited olarak isaretliyorum
	
	char kontrol_kelime[100];								// birazdan alýnan bir elemanýn bir film mi yoksa bir aktor mu belirlenmesi icin kullanýlacak string
	int	aradigimkb[z];										// her aktorun kb sayýsýný kendi inidisyle bulacagýmýz liste
	
	
	for(i=0;i<z;i++)
		aradigimkb[i]=10000;								// oncelikle tum aktorlerýn kb_sayisini 10000 yapýyorum

	char parent[z][150];									// bfs sýrasýnda olusan degiskenin kim tarafýndan olusturuldugunu gosteren liste
			

	// queue islemlerinin basladýgý yer
	
	while(!isEmpty(queue)){								// queue bos kalana kadar devam et
		
		v=dequeue(queue);								// queuenun baþýný cýkar komuslarýný gezmeye basla
			
		temp = graph->adjLists[v];						// cýkartýgýn vertex nolu adjliste git, buradan komsularý queue ya atacagýz
						
		strcpy(kontrol_kelime,graph->adjLists[v]->vertexName);		//  dequeue ettigim kelimeyi kontrol etmek icin kontrol_kelime de saklýyorum

	
			// kevin bacon sayisi bulma islemi burada gerceklesiyor
	
		if(exclamationCheck==1){			// eger exclamationCheck==1 ise bu kelimeden once dequeue ettigimiz kelime bir filmmis anlamýna geliyor
			 
			 
		  if(strchr(kontrol_kelime, '(') != NULL)  {		// suan yeni dequeue ettigimiz kelimede filmse ife giriyor.	'(' içeriyor mu yani film mi dizi mi?
		    exclamationCheck = 1; 					// film olarak isaretliyoruz
		  }
		  
		  else{														// eger bu kelimeden onceki deger filmse ve simdi aktore gecilmisse
		  	kb_sayisi++;											// kb_sayisi ni arttýrýyorum count indextte kb sayisinin degerini sakladýgý icin artýyor
		  	count_index++;					
		  	exclamationCheck=0;										// en son dequeue edilenin bir aktor oldugunu isaretliyorum
	
		  }		
		}
		
		else{								// eger onceki kelime aktorse sadece yeni kelime film mi kontrolu yapýp filmse degeri guncelliyorum
			
			if(strchr(kontrol_kelime, '(') != NULL) {
		    exclamationCheck = 1; 							// ( içeriyor mu yani film m i dizi mi?
		  }			
		}
	   

		while (temp) {		// dequeue ettigim degerin tum komsularýný burada geziyorum
				
		strcpy(kelime,temp->vertexName);		// yeni degeri kelimeye kopyalýyorum
		
		i=0;
		while(strcmp(kelime,yenidegiskenler[i])) 				// film yada aktorun adresini buluyorum.
				i++;
				
		if(visited[i]==0){							// eger daha once gezilmediyse bu aktor veya filmi queue ya atýyorum gezildiyse atmýyorum
		
			enqueue(queue,i);		
			
			
			if(exclamationCheck==0){	//eger bu bir aktorse
				count[count_index]++;		// kb sayýsýndaki aktor miktarýný arttýrýyorum
							
				aradigimkb[i]=kb_sayisi;	// ve bu aktorun kb sayýsýný yerlestiriyorum								
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
	
	
	
	
