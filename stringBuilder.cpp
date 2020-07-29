#include<bits/stdc++.h>
using namespace std;

class node{
   public:
   const char* str;
   node* next;
};

class stringBuilder{
	public:
	node* head; 
	node* tail;
	int size;

	stringBuilder(const char* s1){
		node *temp=new node; 
		temp->str=s1;
		temp->next=NULL;
		head=temp; tail=temp;
		size=strlen(s1);

	}

	stringBuilder(){
        head = NULL;
        size = 0;
    }


};

stringBuilder stringInitialize(const char * str)
{
    stringBuilder sb = stringBuilder(str);
    return sb;
}

void print(stringBuilder s)
{
    node *tmp = s.head;
    while (tmp != NULL)
    {
        cout<<tmp->str ;
        tmp = tmp->next;
    }
}

stringBuilder append(stringBuilder s1, stringBuilder s2){
	//=stringBuilder s3= stringBuilder("");
	//s3.head=s1.head; s3.tail=
	
	//cout<<s1.head->str<<" "<<s1.tail->str<<" "<<s1.tail->next<<endl;
	s1.tail->next=s2.head;
	//cout<<s1.head->str<<" "<<s1.tail->str<<" "<<s1.tail->next<<endl;
	s1.tail=s2.tail;
	//cout<<s1.head->str<<" "<<s1.tail->str<<" "<<s1.tail ->next<<endl;
	s2.tail=NULL;
	s2.head=NULL;
	         
	return s1;

}

  
void findSubstring2(stringBuilder text1, const char* pat) 
{ 
//  const char* pat=pat1.head->str;
    const char*txt=text1.head->str;
    int M=strlen(pat);
    int N=text1.size;
    int count = 0;
    int len = 0; 
    int presuf[M]; 
    presuf[0] = 0; 

    for(int i=1;i<M;) { 
        if (pat[i] == pat[len]) { 
            
            presuf[i] = len+1; 
            len++; 
            i++; 
        } 
        else 
        { 
            if (len != 0) { 
                len = presuf[len - 1]; 
            } 
            else 
            { 
                presuf[i++] = 0; 
                 
            } 
        } 
    } 
 
  
    int j = 0; 
    for(int i=0;i<N;) { 
        if (pat[j] == txt[i]) { 
            i++; 
            j++; 
            
        } 
  
        if (j == M) { 
        	if(count==0){
        		int index=i-j;
            cout<<"Found pattern at index: "<<index<<endl; 
            j = presuf[j - 1];
            count++;
            }
            else{
            	int index =i-j;
            	 cout<<","<<index;
                   j = presuf[j - 1];
                   count++;

            } 
        } 
  
        else if (i < N ) { 
   
            if(pat[j] != txt[i]){
            if (j<=0){ 
            	 i++; 
                }
            else{
               j = presuf[j-1]; 
            }
        }
        } 
    } 
} 
void findSubstring(stringBuilder text1, stringBuilder pat) {
//	stringBuilder pat1=stringBuilder(pat);
findSubstring2(text1, pat.head->str); 
}
  

int main() {  
	stringBuilder str1 =stringBuilder("abc");
	stringBuilder str2 =stringBuilder("def");
    findSubstring(str1,"bc");
    findSubstring(str2,"f");
    
	stringBuilder str3 =append(str1,str2);
    print(str3);

  return 0;
}