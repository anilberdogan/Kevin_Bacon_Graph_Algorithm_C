#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
	
	
	
	
		struct Queue 
	{ 
	    int front, rear, size; 	// quenun basını sonunu sizeını tutan elemanlar
	    unsigned capacity; 		// queuenun kapasitesi
	    int* array; 			
	}; 



	
	struct node {				// bizim graftaki nodelarımız
		char vertexName[150]; 	// aktor veya filmin adı
		int vertex;				// vertexin numarası	
		struct node* next; 		// gezebilmemiz icin nextimiz
		};
		
	
	struct Graph { 
		int numVertices; 			// adjLists icin gereken vertex sayımız
		struct node** adjLists; 	// grafımızı olusturmamızda yardım eden adjList
		};
	
	
	struct node* createNode(char vertex_name[],int vertexNo) {			//  Node olusturma islemi
		
		
		struct node* newNode= malloc(sizeof(struct node)); 				// yeni node u olusturuyoruz
		
		
		newNode->vertex=vertexNo; 										// vertex sayısını, vertex ismini yerlestirip nextini null olarak belirliyoruz
		strcpy(newNode->vertexName,vertex_name);						
		newNode->next = NULL; 
		return newNode; 
		}
	
	
	struct Graph* createGraph(int vertices) { 						// Grafı olusturma
		int i; 														// adjListi NULL lamak icin olusturuyoruz
		struct Graph* graph = malloc(sizeof(struct Graph)); 
		
		graph->numVertices= vertices; 									//vertex numberı yerlestirdik
		graph->adjLists= malloc(vertices * sizeof(struct node*));		// adjListe kac verteximiz var ise o kadar yer acıyoruz
		
		for (i= 0; i< vertices; i++) 
		graph->adjLists[i] = NULL; 								// adjListin ilk önce NULL poizsyona getiriyoruz
		return graph; 	
		}
	
	
	void addEdge(struct Graph* graph, int src, int dest,char vertexName1[],char vertexName2[]) {		// dugumleri birlestirme
	 struct node* newNode= createNode(vertexName2,dest); 					// birlestirecegimiz nodelardan birini yaratıyoruz
	 newNode->next = graph->adjLists[src]; 									// adjListte baglancagı node a baglıyoruz
	 graph->adjLists[src] = newNode; 										// baglanacagı adjListe nodeu ekliyoruz		
	 newNode= createNode(vertexName1,src); 									
	 newNode->next = graph->adjLists[dest]; 								// aynı islemi baglayacagımız ikinci dugum icin yapıyoruz
	 graph->adjLists[dest] = newNode; 
	 } 
		
	
		
	
	struct Queue* createQueue(unsigned capacity) 							// queue olusturma kapasite kadar olusturabiliriz
	{ 
	    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 	// queue ya yer acıyoruz
	    queue->capacity = capacity; 											// kapasitesini belirliyoruz
	    queue->front = queue->size = 0;  										// frontu basa koyuyoruz
	    queue->rear = capacity - 1;  											// enqueue islemi yaparken kontrol etmemiz gerekiyor kapasiteyi rearı kapasitenin bir altı olarak belirliyoruz
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
	        return INT_MIN; 					// eger queue bos ise bisey dondurmemeiz lazım
	    int item = queue->array[queue->front]; 		// Listenin basındaki elemanı alıyoruz
	    queue->front = (queue->front + 1)%queue->capacity; 			// listenin frontunu bir ilerletiyoruz
	    queue->size = queue->size - 1; 				// size ı 1 azaltıyoruz
	    return item; 
	} 
	
	
	
	int front(struct Queue* queue) 			// listenin basındaki elemanı alıp donduruyoruz
	{ 
	    if (isEmpty(queue)) 
	        return INT_MIN; 						
	    return queue->array[queue->front]; 					
	} 
	
	
	int rear(struct Queue* queue) 			// listenin sonundaki elemanı alıp donduruyoruz
	{ 
	    if (isEmpty(queue)) 
	        return INT_MIN; 
	    return queue->array[queue->rear]; 
	} 
		
	
	
	
		
	
	void yazdir (int selected,int count_index,int *count,char yenidegiskenler[MAX][150],char *isim,int * aradigimkb,char parent[MAX][150],int kevin_index){	// yazdırma fonksiyonu
		
		int i;
		
		if(selected==1){		// eger kullanıcı her kb sayısından kacar adet oldugunu gormek istemisse buraya giriyoruz
		printf("kb sayisi 0 olanlar 1 \n");
		for(i=1;i<=count_index;i++)
			printf("kb sayisi %d olanlar %d \n",i,count[i]);		//count adlı her kb sayısından kacar adet oldugunu tutan listemi yazdırıyorum
	
	}
	
	char  yazdirma[4][150]; // Hangi oyunucunun , hangi oyuncuyla aynı filmde oynadıgını tutan listem
	
	int k=0;		// birazdan yazdirma dizisinde gezerken kullanacagım indis
	

	if(selected==2){	// eger kullanıcı Bir aktorun kb a olan uzaklıgını ve nasıl iliski kurdugunu istiyorsa buraya giriyoruz
				
		i=0;
		while(strcmp(isim,yenidegiskenler[i])) 				// aratılan film yada aktorun adresini buluyorum.
				i++;
		
		if(aradigimkb[i]==10000){
			
		printf("%s nin kevin bacon sayisi: sonsuz\n",isim);	
				exit(0);
		}
		
		printf("%s nin kevin bacon sayisi: %d\n",isim,aradigimkb[i]);
		
		strcpy(yazdirma[k],isim); 	// guzel gozukmesi acısından burada alıyorum il aktorumu
		k++;
		
		
		
		while(i!=kevin_index){			// kevin bacona ulasana kadar devam ediyorum
			
			if(k==3){		// eger yazdırma islemi icin hazırsam giriyorum
				
				printf("%s - %s : %s  \n",yazdirma[0],yazdirma[2], yazdirma[1]);		// hangi aktorun hangi aktorle iliski kurdugu ve hangi filmde oynadıklarını yazdırıyorum
				k=1;																	// tekrar yazdırma islemi hazır olana kadar donmek icin k yı 1 yapıyorum
				strcpy(yazdirma[0],yazdirma[2]); 										// son aktorden devam edecegim icin son aktoru 0. indise kopyalıyorum
			}
			strcpy(yazdirma[k],parent[i]);			// yazdirma listesine i. aktor veya filmin olsutugu aktor ya da filmi aktarıyorum
			
			i=0;
			while(strcmp(yazdirma[k],yenidegiskenler[i])) 				// film yada aktorun adresini buluyorum. 
				i++;
			
			k++; 
		
		}	
	
		printf("%s - %s : %s  \n",yazdirma[0],yazdirma[2], yazdirma[1]);	// ne son kevin baconlı satırı da yazdırıyorum

	}		
	}
	
	
	
	
	
	
///////////////////////////////////////////////           MAIN               ///////////////////////////////////////////	
	
	
	

	int main(){
		
		int i=0,j;
		int result,ekleme=0,k,z=0;
		
		char *a;										// tum satırları strtok ile gezerken / ile ayırdıgım elemanları tuttugum iki char array
		char *b;
		
		char dosya[30];									// input alacagım dosyanın adı
		char buf[MAX];									// input alırken kullanacagım buffer
		char isim[200];									// kullanıcının aramak istedigi isim
		char bos[10];									// gets islemi sırasında olusan hatayı onlemek adına yaratılmıs bir string
		
		char degiskenler[8000][150];					// Tum / ile ayrılmış olan elemanları tuttugum liste
		int selected;									// Kullanıcının hangi islemi yapmak istedigini anladıgım deger 1 ise kb degerlerini yazdırır, 2 ise verilen ismin kb olan uzaklıgı gosterilir.
		
		printf("Okumak istediginiz dosyanin adini giriniz: ");
		scanf("%s",&dosya);
		
		printf("Her Kevin bacon sayisindan kacar tane oldugunu gormek icin 1'e\n(Soyad, Ad) formatinda yazilmis kisinin kevin bacon sayisini ogrenmek icin 2'ye basin'");
		scanf("%d",&selected);
		
		if(selected==2){
			gets(bos);												// onceki inputta entera basıldıgında hata cıkmaması icin kullanılıyor
			printf("Ismi giriniz: ");
			gets(isim); 											// kullanıcının kevin baconla mesafesini merak ettigi ismi alıyoruz
			
		}

		
		FILE * ptr;													// ulasacagımız dosya icin bir file pointer yaratıyoruz
		FILE * fp;													// daha sonra dosyaın basından itibaren tekrar gezecegimiz icin 2. fıle pointerı tanımlıyoruz
		
		ptr=fopen(dosya,"r");										// dosyayı aciyoruz
		
		 
		while(fgets(buf,MAX,ptr)){			// Dosyanın sonuna kadar devam ediyor ve satır satır alıyor
			
			a=strtok(buf,"\n");				// Herhangi bir sorun cıkmaması acısından once satıra gore ayırıyorum
			b=strtok(a,"/");				// Ardından elemanlarımı '/' isaretine gore ayırıyorum
			while(b!=NULL){					// O satırın sonuna kadar '/' isaretiyle ayırmaya devam et
				
				strcpy(degiskenler[i],b);		// aldıgın elemanı degiskenler listesine koy
				b=strtok(NULL,"/");				// bir sonraki elemana gec
				i++;							// degiskenler listesinin sonraki elemanına gec
			
		}	
	}		
	

	
	char yenidegiskenler[i][150];			// degiskenler listesinde tutulan elemanların bazıları 1 den fazla kez listede gectiginden adjLists icin vertex number hesaplanması ve daha sonradan
											// isime cok yarayacagı icin her elemanın birer kez gececegi yenidegiskenler listem. i tane eleman oldugundan bu sekilde boyutunun belirlenmesi yeterli
	
	
	for(j=0;j<i;j++){					// degiskenler listesinin tum elemanları geziyorum
		
		strcpy(a,degiskenler[j]);		// elemanımı bir stringe atıp sonraki elemanlarla karsilastiriyorum tekrar geciyor mu diye
		
		for(k=j+1;k<i;k++){				// karsilastirmaya sonraki elemandan basliyorum
			
			result=strcmp(a,degiskenler[k]);			// listede kendinden sonra bidaha kendisi geçiyorsa eklemiyor atlıyor 														// ve en sonda kendinden sonra eleman kalmayacıgı icin en son esdeger elemanı listeye koyuyor
		
			if(result==0){
				ekleme=1;								// eleman sonradan da gectigi icin eklememesi gerektigini belirtiyor
				break;
		}			
	}
		
		if(ekleme==0){
			
			strcpy(yenidegiskenler[z],a);			// eger eklenmesinde sorun yoksa sorun yoksa ekliyor ve z yi arttıryor. Bu z degerimiz ileride cok kullanacagımız 
													// yenidegiskenler listemizin boyutunu belirtecek aynı zamanda vertex sayimiz olacak
			z++;
		}	
		ekleme=0;		// kontrollere devam edebilmek icin resetliyoruz		
	}
		
	int sorunYok=0;			// kelimenın var olup olmadıgı kontrolu
		
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
	graph=createGraph(z);		// z vertex sayımız oldugundan adjListsimizin de boyutu olacak. adjList olustu
	

	/////////////////// AD EDGE /////////////////
	
	
	fp=fopen(dosya,"r");  		// dosyayı tekrar bastan itibaren gezmem gerektigi icin tekrar acıyorum

	int movie_index;		// filmin adresi
	struct node* newNode;	// yeni node referansı
	char movie[100];	// film adını tutmak icin
	char actor[50];		// actor adını tutmak icin
	char *d;			// her satırı tutmak icin gereken string
	char *e;			// her satırda bulunan '/' ile ayrılan elemanları tutmak icin gereken string
	
	
	while(fgets(buf,MAX,fp)){	// dosyanın sonuna kadar devam et		
					
			d=strtok(buf,"\n");		// satırı d ye al
			e=strtok(d,"/");		//  	'/' ile ayrılmıs elemanları e ye al
			strcpy(movie,e);		// filmin adını kopyala			
		
			j=0;
			while(strcmp(movie,yenidegiskenler[j]))		// filmin indexini bul
			j++;
		
			movie_index=j;
				
			e=strtok(NULL,"/");					// aktorlere gec
		
			while(e!=NULL){		// aynı satırdaki yani o filmin aktorleri bitene kadar
					
				i=0;
				while(strcmp(e,yenidegiskenler[i]))			// aktorlerın indisini bul 
				i++;
			
				addEdge(graph,movie_index,i,movie,e);		// aktor ile film arasındaki edge i olustur yani graph olusuyor
				
				e=strtok(NULL,"/");
		}		
	}		
	
 	
 		

	////////////////////////BFS BAŞLANGICI //////////////////////////////////////////
	
		
	int kevin_index; 	// kevin baconun bulundugu adres
	
	char kevin[12]={'B','a','c','o','n',',',' ','K','e','v','i','n'}; 	// kevin baconu kevin isimli chara atadım
		

	i=z;		// i yi son elemandan baslattım	
	while(strcmp(kevin,yenidegiskenler[i]))		// öndende başlatabilirdim ama en son kevin baconu bulacagı icin daha kısa surer
				i--;

	kevin_index=i;		//k evin baconun adresi belirlendi
		
	int visited[z];		// queue da kullanacıgım o eleman daha once ziyaret edildimi kontrolu ıcın visited dizimi olusturdum
	
	for(i=0;i<z;i++)		
		visited[i]=0;		// her indexin visitedını 0 yaptım bu gezilmedi anlamına geliyor
	
	
	int kb_sayisi=0;		//kb sayısını belirleycek olan degisken
	int count[100];			// her kb sayisindan kacar tane var belirleyen degisken
	
	for(i=0;i<100;i++)		
		count[i]=0;			// tum kb sayılarından basta 0 tane var
	
		
	int count_index=0;			// kb adımlarında kullanılacak olan countun indexini degistirecek olan degisken
	struct node* temp;
	int v,exclamationCheck=1;			// Bu degisken 1 ise bir film var elimizde , 0 ise bir aktor var elimizde .
										// en son filmde miydi aktörde miydi onu belirtiyor, filmden aktöre geçince kb_sayisi artıyor
	
	struct Queue* queue = createQueue(z);		// queue yu eleman sayım olan z ye gore olusturdum
	
	char kelime[150];										// birazdan queue icinde bfs yaparken ortaya cıkan film ve oyuncu isimlerini bir sure saklayacagım string
	enqueue(queue,kevin_index);								// En başta kevin baconı queue ya atıyorum
	visited[kevin_index]=1;									// kevin baconu visited olarak isaretliyorum
	
	char kontrol_kelime[100];								// birazdan alınan bir elemanın bir film mi yoksa bir aktor mu belirlenmesi icin kullanılacak string
	int	aradigimkb[z];										// her aktorun kb sayısını kendi inidisyle bulacagımız liste
	
	
	for(i=0;i<z;i++)
		aradigimkb[i]=10000;								// oncelikle tum aktorlerın kb_sayisini 10000 yapıyorum

	char parent[z][150];									// bfs sırasında olusan degiskenin kim tarafından olusturuldugunu gosteren liste
			

	// queue islemlerinin basladıgı yer
	
	while(!isEmpty(queue)){								// queue bos kalana kadar devam et
		
		v=dequeue(queue);								// queuenun başını cıkar komuslarını gezmeye basla
			
		temp = graph->adjLists[v];						// cıkartıgın vertex nolu adjliste git, buradan komsuları queue ya atacagız
						
		strcpy(kontrol_kelime,graph->adjLists[v]->vertexName);		//  dequeue ettigim kelimeyi kontrol etmek icin kontrol_kelime de saklıyorum

	
			// kevin bacon sayisi bulma islemi burada gerceklesiyor
	
		if(exclamationCheck==1){			// eger exclamationCheck==1 ise bu kelimeden once dequeue ettigimiz kelime bir filmmis anlamına geliyor
			 
			 
		  if(strchr(kontrol_kelime, '(') != NULL)  {		// suan yeni dequeue ettigimiz kelimede filmse ife giriyor.	'(' içeriyor mu yani film mi dizi mi?
		    exclamationCheck = 1; 					// film olarak isaretliyoruz
		  }
		  
		  else{														// eger bu kelimeden onceki deger filmse ve simdi aktore gecilmisse
		  	kb_sayisi++;											// kb_sayisi ni arttırıyorum count indextte kb sayisinin degerini sakladıgı icin artıyor
		  	count_index++;					
		  	exclamationCheck=0;										// en son dequeue edilenin bir aktor oldugunu isaretliyorum
	
		  }		
		}
		
		else{								// eger onceki kelime aktorse sadece yeni kelime film mi kontrolu yapıp filmse degeri guncelliyorum
			
			if(strchr(kontrol_kelime, '(') != NULL) {
		    exclamationCheck = 1; 							// ( içeriyor mu yani film m i dizi mi?
		  }			
		}
	   

		while (temp) {		// dequeue ettigim degerin tum komsularını burada geziyorum
				
		strcpy(kelime,temp->vertexName);		// yeni degeri kelimeye kopyalıyorum
		
		i=0;
		while(strcmp(kelime,yenidegiskenler[i])) 				// film yada aktorun adresini buluyorum.
				i++;
				
		if(visited[i]==0){							// eger daha once gezilmediyse bu aktor veya filmi queue ya atıyorum gezildiyse atmıyorum
		
			enqueue(queue,i);		
			
			
			if(exclamationCheck==0){	//eger bu bir aktorse
				count[count_index]++;		// kb sayısındaki aktor miktarını arttırıyorum
							
				aradigimkb[i]=kb_sayisi;	// ve bu aktorun kb sayısını yerlestiriyorum								
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
	
	
	
	
