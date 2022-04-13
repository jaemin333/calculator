#include <stdio.h>

#define TRUE 1
#define FALSE 0

int Equal(int a, int b){
	if(a==b){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

int notEqual(int a, int b){
	if(Equal(a,b)){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

int PlusOne(int a){	
	return ++a;
}

int greater_than(int a,int b){
	
	int originB = b; 
	int originA = a;
	
	while(1){
		a =PlusOne(a);
		b =PlusOne(b);
		if(Equal(b,originA)){
			return TRUE;
		}
		
		else if(Equal(a,originB)){
			return FALSE;
		}
		
		else{
			continue;
		}
	}
}	

int lesser_than(int a,int b){
	if(greater_than(a,b)){
		return FALSE;
	}
	
	else{
		return TRUE;
	}
	
}

int PlusBothPositive(int a, int b){
	int i = 0;
	int sum = 0;
	int j =0;
	while(notEqual(i,a)){
		sum = PlusOne(sum);
		i = PlusOne(i);
	}
			
	while(notEqual(j,b) ){
		sum = PlusOne(sum);
		j = PlusOne(j);
	}
	
	return sum;
		
}

int PlusPositiveNegative(int a,int b){
	int k = 0;
	int sum = b;
	while(notEqual(k,a)){
		sum = PlusOne(sum);
		k = PlusOne(k);
	}
	
	return sum;
	
}

void PlusBothNegative(int a, int b){
	int PosA = 0;
	int PosB = 0;
	int sum;
	while(notEqual(a,0)){
		a = PlusOne(a);
		PosA = PlusOne(PosA);
	}
	
	while(notEqual(b,0)){
		b= PlusOne(b);
		PosB = PlusOne(PosB);
	}
	
	sum = PlusBothPositive(PosA,PosB);
	printf("m%d\n",sum);
	

}

int minusBothPositive(int a, int b){
	int sum = 0;
	int i =0;
	if(greater_than(a,b)){
		while(notEqual(b,a)){
			sum = PlusOne(sum);
			b = PlusOne(b);
		}
	}
	
	
	
	return sum;
}


int minusPositiveNegative(int a,int b){   
	int sum = a;
	int i =0;
	while(notEqual(b,0)){
		b = PlusOne(b);
		sum = PlusOne(sum);
	}
	
	return sum;
}

void minusBothNegative(int a,int b){
	int sum;
	  
	if(greater_than(a,b)){
		int PosA = 0;
		int PosB = 0;
		while(notEqual(a,0)){
			a = PlusOne(a);
			PosA = PlusOne(PosA);
		}
		
		while(notEqual(b,0)){
			b = PlusOne(b);
			PosB = PlusOne(PosB);
		}
		
		sum = minusBothPositive(PosB,PosA);
		
		printf("%d",sum);
		}
		
	else{
		
		int PosA = 0;
		int PosB = 0;
		while(notEqual(a,0)){
			a = PlusOne(a);
			PosA = PlusOne(PosA);
		}
		
		while(notEqual(b,0)){
			b = PlusOne(b);
			PosB = PlusOne(PosB);
		}
		
		sum = minusBothPositive(PosA,PosB);
		printf("m%d",sum);
		
	}
	
}


int multipleBothPositive(int a, int b){
	int i = 0;
	int sum = 0;
	
	while(notEqual(i,a)){
		int j = 0;
		while(notEqual(j,b)){
			sum = PlusOne(sum);
			j = PlusOne(j);
		}
		
		i = PlusOne(i);
		
	}
	
	
	return sum;
}

int multipleBothNegative(int a, int b){
	int PosA=0;
	int PosB=0;
	int result;
	
	while(notEqual(a,0)){
		PosA = PlusOne(PosA);
		a = PlusOne(a);
	}
	
	while(notEqual(b,0)){
		PosB = PlusOne(PosB);
		b = PlusOne(b);
	}
	
	
	result = multipleBothPositive(PosA,PosB);
	return result;
	
}

 
void multiplePositiveNegative(int a, int b){
	int PosB = 0;
	int result;
	
	while(notEqual(b,0)){
		PosB = PlusOne(PosB);
		b = PlusOne(b);
	} 
	
	result = multipleBothPositive(a,PosB);
	
	printf("m%d",result);
	
	
}
	
void divisionBothPositive(int a, int b){
	int result = 1;
	
	if(greater_than(b,a)){
		printf("remainder is %d", a); 
	}
	
	else {
		while(1){
			
			if(Equal(multipleBothPositive(b,result),a)){
				printf("quotient is %d\n", result);
				printf("remainder %d\n",minusBothPositive(a,multipleBothPositive(b,result)));
				break;
			}
			
			else if(greater_than(multipleBothPositive(b,result),a)){
				printf("quotient is %d\n", minusBothPositive(result,1));
				printf("remainder is %d\n",minusBothPositive(a,multipleBothPositive(b,minusBothPositive(result,1))));
				break;
			}
			
			else{
				result = PlusOne(result);
			}
			
		}
		
	}
}

void divisionPositiveNegative(int a,int b){
	int result = 1;
	
	int PosB = 0;
	while(notEqual(b,0)){
		PosB = PlusOne(PosB);
		b = PlusOne(b);
	} 
	
	
	
	while(1){
			
		if(Equal(multipleBothPositive(PosB,result),a)){
			printf("quotient is m%d", result);
			printf("remainder is %d\n",minusBothPositive(a,multipleBothPositive(PosB,result)));
			break;
		}
			
		else if(greater_than(multipleBothPositive(PosB,result),a)){
			printf("quotient is m%d", minusBothPositive(result,1));
			printf("remainder is %d\n",minusBothPositive(a,multipleBothPositive(PosB,minusBothPositive(result,1))));
			break;
		}
			
		else{
			result = PlusOne(result);
		}
			
		}
		
	
}

int main(){
	int result;
	int menu;
	printf("+ is 1 - is 2 * is 3 / is 4\n");
	scanf("%d",&menu); 
	int a;
	int b;
	printf("insert two numbers ");
	scanf("%d",&a);
	scanf("%d",&b);
	
	if(Equal(menu,1)){
		
		if(Equal(a,0)){
			printf("%d",b);
		}
		
		
		if(greater_than(a,0)){
			
			if(Equal(b,0)){
				printf("%d",a);
			}
			
			if(greater_than(b,0)){
				result = PlusBothPositive(a,b);
				printf("%d",result);
			}
			
			if(lesser_than(b,0)){
				result = PlusPositiveNegative(a,b);
				printf("%d",result);
			}
			
		}
		
		if(lesser_than(a,0)){
			if(Equal(b,0)){
				printf("%d",a);
			}
			
			if(greater_than(b,0)){
				result = PlusPositiveNegative(b,a);
				printf("%d",result);
			}
			
			if(lesser_than(b,0)){
				PlusBothNegative(a,b);
			}
			
			
		}
		
	} 
	
	else if(Equal(menu,2)){
		if(Equal(a,0)){
			printf("m%d",b);
		}
		
		if(Equal(a,b)){
			printf("0");
		}
		
		if(greater_than(a,0)){
			
			if(Equal(b,0)){
				printf("%d",a);
			}
			
			if(greater_than(b,0)){
				if(greater_than(a,b)){
					result = minusBothPositive(a,b);
					printf("%d",result);
			}
				if(greater_than(b,a)){
					result = minusBothPositive(b,a);
					printf("m%d",result);
				}
			}
			
			if(lesser_than(b,0)){
				result = minusPositiveNegative(a,b);
				printf("%d",result);
			}
			
		}
		
		if(lesser_than(a,0)){
			if(Equal(b,0)){
				printf("%d",a);
			}
			
			if(greater_than(b,0)){
				result = minusPositiveNegative(b,a);
				printf("m%d",result);
			}
			
			if(lesser_than(b,0)){
				minusBothNegative(a,b);
			}
			
			
		}
		
		
	}
	
	else if(Equal(menu,3)){
		
		if(Equal(a,0)){
			printf("0");
		}
		
		if(Equal(b,0)){
			printf("0");
		}
		
		
		
		if(greater_than(a,0)){
			if(greater_than(b,0)){
				result = multipleBothPositive(a,b);
				printf("%d",result);
			}
			
			if(lesser_than(b,0)){
				multiplePositiveNegative(a,b);
			}
			
		}
		
		if(lesser_than(a,0)){
			if(greater_than(b,0)){
				multiplePositiveNegative(b,a);
			}
			
			if(lesser_than(b,0)){
				result = multipleBothNegative(a,b);
				printf("%d",result);
			}
			
			
			
		}
		
	}
	
	else if(Equal(menu,4)){
		if(greater_than(a,0)){
			if(greater_than(b,0)){
				divisionBothPositive(a,b);
			}
			
			else{
				divisionPositiveNegative(a,b);
			}
		}
		
		
	}

	
	return 0;
}
