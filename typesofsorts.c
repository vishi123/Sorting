#include<stdio.h>

void selection(int a[], int n){
	int min,i,j,temp;
	for(i=0; i<n-1; i++){
		min=i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[min])
			min=j;
		}
		temp=a[i];
	    a[i]=a[min];
	    a[min]=temp;
	}
	for(i=0; i<n; i++){
		printf("\t%d", a[i]);
	}
	printf("\n");
}
void insertion(int a[],int n){
	int i,j,k;
	for(i=1; i<n; i++){
		k=a[i];
		j=i-1;
		while(j>=0 && a[j]>k){
			a[j+1]=a[j];
			j=j-1;
			}
		a[j+1]=k;
		
	}
	for(i=0; i<n; i++){
		printf("\t%d", a[i]);
	}
	printf("\n");
}


void bubble(int a[], int n){
	int i,j,k,flag,temp;
	for(k=1; k<n; k++){
		flag=0;
		for(i=0; i<n-k; i++){
			if(a[i]>a[i+1])
			{
			temp=a[i];
	       a[i]=a[i+1];
	       a[i+1]=temp;
			flag=1;
		}
		}
		if(flag==0)
		break;
	}
	for(i=0; i<n; i++){
		printf("\t%d", a[i]);
	}
	printf("\n");
}

void merge(int a[],int p, int q, int r){
	int i,j,k;
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1],R[n2+1];
	for(i=1; i<=n1; i++){
		L[i]=a[p+i-1];
	}
	
	for(j=1; j<=n2; j++){
		R[j]=a[q+j];
	}
	L[n1+1]=99;
	R[n2+1]=99;
	
	i=1, j=1;
	for(k=p; k<=r; k++){
		if(L[i]<=R[j])
		{a[k]=L[i];
		i++;}
		else
		{a[k]=R[j];
		j++;}
	}
	
}

void mergesort(int a[], int p, int r){
	if(p<r)
	{ int q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

int partition(int a[], int p, int r){
	int temp;
	int x=a[r];
	int j,i=p-1;
	for(j=p; j<r; j++){
		if(a[j]<=x){
			i=i+1;
			temp=a[i];
	       a[i]=a[j];
	       a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	
	return i+1;
}

void quicksort(int a[], int p, int r){
	if(p<r){
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

void heapify(int a[], int n, int i){
	int temp, largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[i])
	largest=l;
	if(r<n && a[r]>a[largest])
	largest=r;
	if(largest!=i){
		temp=a[i];
	    a[i]=a[largest];
	    a[largest]=temp;
	    heapify(a,n,largest);
}
}

void heapsort(int a[], int n){
	int temp,i;
	for(i=n/2-1; i>=0; i--)//build heap
	heapify(a,n,i);
	
	for(i=n-1; i>=0; i--){
	temp=a[0];
	a[0]=a[i];
    a[i]=temp;
	heapify(a,i,0);	
	}
}

int main(){
	int i,j,n,op;
	printf("enter the no. of elements: ");
	scanf("%d", &n);
	int a[n];
	printf("\nenter the elements: ");
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	printf("\nenter the sorting operations:\n1 for insertion sort\n2 for selection sort\n3 for bubble sort\n4 for merge sort\n5 for quick sort\n6 for heap sort\n");
   while(1){
   	scanf("\n%d",&op);
	switch(op) {
		    case 1:{
			printf("\noutput by insertion sort: ");
			insertion(a, n);
			    break;
			}
			
			case 2:{printf("\noutput by selection sort: ");
			selection(a, n);
			    break;
			}
			
			case 3:{printf("\noutput by bubble sort: ");
			bubble(a, n);
				break;
			}
			
			case 4:{printf("\noutput by merge sort: ");
			mergesort(a, 0, n-1);
			  for(i=0; i<n; i++){
	        	printf("\t%d", a[i]);
				}
	        	printf("\n");
        

			break;
				
			}
			case 5:{printf("\noutput by quick sort: ");
			quicksort(a, 0, n-1);
			   for(i=0; i<n; i++){
		          printf("\t%d", a[i]);
		      }
		          printf("\n");
	        

				break;
	    	}
	    	
	    	case 6: {printf("\noutput by heap sort: ");
			heapsort(a, n);
			   for(i=0; i<n; i++){
		          printf("\t%d", a[i]);
		      }
		          printf("\n");
	        

				break;
	    	}
	    	
			default:{
				printf("\ntype 1 to 6 to execute: ");
				scanf("%d",&op);
				printf("\nenter the sorting operations:\n1 for insertion sort\n2 for selection sort\n3 for bubble sort\n4 for merge sort\n5 for quick sort\n6 for heap sort\n");
				
				break;
			}
		     
}
}
	
}
