# include<stdio.h>
# include<stdlib.h>
# include<string.h>

void displayTable(int t,int *table){
    printf("Index   Values \n");
    for(int i=0;i<t;i++){
        printf("  %d       %d \n",i,table[i]);
    }
}

void doubleHashing(int t,int k,int *table,int *keys){
    int j=1;
    // g(k)=1+keymod(tablesize-1);
    for(int i=0;i<k;i++){
        int ans=keys[i]%t;
        if(table[ans]==-1){
            table[ans]=keys[i];
            printf("%d is insert at %d index of table. \n",keys[i],ans);
        }
        else {
            printf("%d collision is occured at index %d. \n",j,ans);
            j++;
            int p=1;
            int index=ans;
            int a=ans;
            int g=1+keys[i]%(t-1);
            while(table[index]!=-1){
                printf("%dth probing. \n",p);
                index=(a+p*g)%t;
                printf("index=(ans+p*g(k))mod(tablesize) \n");
                printf("index=(%d+%d*%d)mod%d=%d \n",a,p,g,t,index);
                p++;
                ans++;
                ans=ans%t;
            }
            table[index]=keys[i];
            printf("%d is insert at %d index of table. \n",keys[i],ans);
        }
    }
    printf("Double Hasing Table is : \n");
    displayTable(t,table);
}
void quadraticProbing(int t,int k,int *table,int *keys){
    int j=1;
    for(int i=0;i<k;i++){
        int ans=keys[i]%t;
        if(table[ans]==-1){
            table[ans]=keys[i];
            printf("%d is insert at %d index of table. \n",keys[i],ans);
        }
        else {
            printf("%d collision is occured at index %d. \n",j,ans);
            j++;
            int p=1;
            int index=ans;
            int a=ans;
            while(table[index]!=-1){
                printf("%dth probing. \n",p);
                index=(a+p*p)%t;
                printf("index=(ans+p*p)mod(tablesize) \n");
                printf("index=(%d+%d*%d)mod%d=%d \n",a,p,p,t,index);
                p++;
                ans++;
                ans=ans%t;
            }
            table[index]=keys[i];
            printf("%d is insert at %d index of table. \n",keys[i],ans);
        }
    }
    printf("Quadratic Hasing Table is : \n");
    displayTable(t,table);
}

void linearProbing(int t,int k,int *table,int *keys){
    int j=1;
    for(int i=0;i<k;i++){
        int ans=keys[i]%t;
        if(table[ans]==-1){
            table[ans]=keys[i];
            printf("%d is insert at %d index of table. \n",keys[i],ans);
        }
        else {
            printf("%d collision is occured at index %d. \n",j,ans);
            j++;
            int p=1;
            int index=ans;
            int a=ans;
            while(table[index]!=-1){
                printf("%dth probing. \n",p);
                index=(a+p)%t;
                printf("index=(ans+p)mod(tablesize) \n");
                printf("index=(%d+%d)mod%d=%d \n",a,p,t,index);
                p++;
                ans++;
                ans=ans%t;
            }
            table[index]=keys[i];
            printf("%d is insert at %d index of table. \n",keys[i],ans);
        }
    }
    printf("Linear Hasing Table is : \n");
    displayTable(t,table);
}
int main(){
    int tablesize1;
    int tablesize2;
    int noOfKeys;
    printf("Enter the table size for linear and quadratic hashing : ");
    scanf("%d",&tablesize1);
    printf("Enter the table size for double hashing : ");
    scanf("%d",&tablesize2);
    printf("Enter the number of keys : ");
    scanf("%d",&noOfKeys);
    int *table1=(int *)malloc(tablesize1*sizeof(int));
    int *table2=(int *)malloc(tablesize1*sizeof(int));
    int *table3=(int *)malloc(tablesize2*sizeof(int));
    int *keys=(int *)malloc(noOfKeys*sizeof(int));
    for(int i=0;i<tablesize1;i++){
        table1[i]=-1;
        table2[i]=-1;
    }
    for(int i=0;i<tablesize2;i++){
        table3[i]=-1;
    }
    printf("Enter values for keys in an array : \n");
    for(int i=0;i<noOfKeys;i++){
        scanf("%d",&keys[i]);
    }
    printf("The linear Hasing is : \n\n");
    linearProbing(tablesize1,noOfKeys,table1,keys);
    printf("\n");
    printf("The Quadratic Hasing is : \n\n");
    quadraticProbing(tablesize1,noOfKeys,table2,keys);
    printf("\n");
    printf("The Double Hasing is : \n\n");
    doubleHashing(tablesize2,noOfKeys,table3,keys);

    

    return 0;
}