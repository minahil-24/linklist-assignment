#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
using namespace std;
///////////////////////// LINKLIST CLASS /////////////////////////////////////
class linklist {
public :
    int mainlist ()
    {   int choice;
        cout<<endl<<endl<<endl;
        cout<<setw(172)<<"1.Singly Linklist"<<endl;
        cout<<setw(172)<<"2.Doubly Linklist"<<endl;
        cout<<setw(181)<<"3.Circular Singly Linklist"<<endl;
        cout<<setw(181)<<"4.Circular Doubly Linklist"<<endl<<endl<<endl;
        cout<<" Please Enter your Choice : ";
        while(!(cin>>choice&&choice>=1&&choice<=4))
        {   cin.clear();
            cin.ignore();
            cout<<endl<<"Invalid Input !  Enter Again.......  : ";
        }
        return choice;
    }
    int functionList(int list)
    {   cout<<endl<<endl;
        for(int i=1; i<=1; i++) {
cout<<setw(76)<<"(((((((((((((((((((((((((((((()))))))))))))))))))))))))))))) "<<endl<<endl;
            cout<<setw(30)<<i<<". Add at First Position "<<endl;
            cout<<setw(30)<<++i<<". Add at Last Position"<<endl;
            cout<<setw(30)<<++i<<". Delete First Position Value"<<endl;
            cout<<setw(30)<<++i<<". Delete Last Position Value"<<endl;
            cout<<setw(30)<<++i<<". Insert at any Position"<<endl;
            cout<<setw(30)<<++i<<". Search Value"<<endl;
            cout<<setw(30)<<++i<<". Count your Nodes"<<endl;
            cout<<setw(30)<<++i<<". Maximum Value of linklist"<<endl;
            cout<<setw(30)<<++i<<". Average of linklist"<<endl;
            cout<<setw(30)<<++i<<". Reverse Linklist"<<endl;
            cout<<setw(30)<<++i<<". Detect the Loop"<<endl;
            if(list==1)
            {
                cout<<setw(30)<<++i<<". Palindrome "<<endl;
            }
            cout<<setw(30)<<++i<<". Back to Mainlist"<<endl<<endl;
            cout<<setw(76)<<"(((((((((((((((((((((((((((((()))))))))))))))))))))))))))))) "<<endl<<endl;
            int choice;
            if(list==1)
            {
                cout<<endl<<endl<<" Please Enter your Choice : ";
                while(!(cin>>choice&&choice>=1&&choice<=13))
                {   cin.clear();
                    cin.ignore();
                    cout<<endl<<"Invalid Input !  Enter Again.......  : ";
                }
            }
            else
            {
                cout<<endl<<endl<<endl<<" Please Enter your Choice : ";
                while(!(cin>>choice&&choice>=1&&choice<=12))
                {   cin.clear();
                    cin.ignore();
                    cout<<endl<<"Invalid Input !  Enter Again.......  : ";
                }
            }

            return choice;
        }
    }
};
///////////////////////// Singly LINKLIST CLASS /////////////////////////////////////
class SinglyNode {
private :
    int number;
    SinglyNode* next;
public :
    void show()
    {   if(head==NULL)
        {   cout<<"NOTHING IN LINKLIST......"<<endl;
        }
        else {

            SinglyNode* temp=head;
            while(temp!=NULL)
            {   cout<<temp->number<<" ";
                temp=temp->next;
            }
        }
    }
    SinglyNode() {
    }
    SinglyNode (int newValue)
    {   next=NULL;

    }
    SinglyNode* head=NULL;
    void addFirst(int newValue)
    {   SinglyNode* newNode= new SinglyNode(newValue);
        newNode->number=newValue;
        if(head==NULL) {
            head = newNode;
            cout<<endl<<"Add at First SUCCESSFULLY....."<<endl;
        }
        else {
            newNode->next = head;
            head = newNode;
            cout<<endl<<"Add at First SUCCESSFULLY....."<<endl;
        }

    }
    void addLast(int newValue)
    {   SinglyNode* newNode= new SinglyNode(newValue);
        newNode->number=newValue;
        if(head==NULL)
        {
            head = newNode;
        }

        else {
            SinglyNode * temp = head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;

        }
    }
    void deleteFirst() {
        if(head==NULL)
        {   cout<<" Linklist is empty ! Add Values First......."<<endl;
        }
        else {

            SinglyNode * temp = head;
            head=temp->next;
            delete temp;
            cout<<endl<<" Delete sucessfully.."<<endl;

        }
    }
    void deleteLast ()
    {    SinglyNode * temp = head;
	if(head==NULL)
        {   cout<<" Linklist is empty ! Add Values First......."<<endl;

        }
        else if(head->next==NULL) {
            head=NULL;
            delete temp;
            cout<<" Delete sucessfully.."<<endl;
        }
        else {
           
            SinglyNode * prev=head;
            while(temp->next!=NULL)
            {   prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            delete temp;


            cout<<" Delete sucessfully.."<<endl;

        }
    }
    void insertat(int index,int newValue)
    {   if(head==NULL)
        {   cout<<"Linklist not Exist .... Please ADD something"<<endl<<endl;
        }
        else {

            int valid=countNodes();
            if(index>=1&&index<=valid) {
                if(index==1)
                {   SinglyNode::addFirst(newValue);
                }
                else {

                    SinglyNode* newNode= new SinglyNode(newValue);
                    newNode->number=newValue;
                    SinglyNode * temp = head;

                    for(int i=1; i<index-1; i++)
                    {
                        temp=temp->next;

                    }

                    newNode->next=temp->next;
                    temp->next=newNode;
                    //show();
                }
            }
            else {

                cout<<"Sorry ! index is not in our linklist ...."<<endl;
                cout<<"Your Index must be 1 to "<<valid<<endl;
            }
        }
    }
    int countNodes()
    {   int counter=1;
        if(head==NULL)
        {   counter=0;
            cout<<"Kindly ! Add Something First then Count "<<endl;
        }
        else {

            SinglyNode*temp=head;
            while(temp->next!=NULL)
            {   counter++;
                temp=temp->next;

            }

        }
        return counter;
    }
    void searchValue(int searchvalue)
    {   if(head==NULL)
            cout<<"Kindly Add something to search"<<endl;
        else
        {   int found=0;
            SinglyNode *temp=head;

            while(temp!=NULL)
            {
                if(temp->number==searchvalue)
                {
                    cout<<"Number Found"<<endl;
                    found++;

                }
                temp=temp->next;
            }
            if(found==0)
            {   cout<<"Sorry ! Number Not found "<<endl;
            }
        }
    }
    void maximum() {
        if(head==NULL)
            cout<<"Kindly Add something "<<endl;
        else {

            SinglyNode*temp=head;
            int max=temp->number;
            while(temp!=NULL) {
                if(max<temp->number) {
                    max=temp->number;
                }
                temp=temp->next;
            }
            cout<<"Maximun value in this linklist is : "<<max<<endl;
        }
    }
    void average()
    {   if(head==NULL)
            cout<<"Kindly Add something First "<<endl;
        else {
            float average;
            SinglyNode*temp=head;
            while(temp!=NULL)
            {   average+=temp->number;
                temp=temp->next;
            }
            average=(average/countNodes());
            cout<<"Average of our Linklist is : "<<average<<endl;
        }
    }
    void reverse()
    {   if(head==NULL)
            cout<<"Kindly Add something First "<<endl;
        else {
            SinglyNode* prev=NULL;
            SinglyNode* curr=head;
            SinglyNode* temp=NULL;

            while(curr!=NULL)
            {   prev=temp;
                temp=curr;
                curr=curr->next;
                temp->next=prev;




            }
            head=temp;
//show();
        }
    }

    void detectLoop() {
        int flag=0;
        if(head==NULL||head->next==NULL) {
            cout<<"There is no loop in linklist ! if linklist is empty or only 1 Node......."<<endl;

        }
        else {
            SinglyNode * Slow =head;
            SinglyNode * Fast =head->next;
            while(Fast !=NULL && Fast->next !=NULL)
            {   if(Slow==Fast) {
                    cout<<"Loop Detected in this Linklist "<<endl;
                    flag++;
                }
                Slow=Slow->next;
                Fast=Fast->next->next;
            }

            if(flag==0) {
                cout<<"Loop Not Detected in this Linklist"<<endl;
            }
        }
    }
    void palindrome() {
        if(head==NULL) {
            cout<<"Nothing in linklist......."<<endl;

        }
        else {
            SinglyNode*slow=head;
            SinglyNode*fast=head;
            while(fast!=NULL&&fast->next!=NULL)
            {   slow=slow->next;
                fast=fast->next->next;
            }

            SinglyNode* prev=NULL;
            SinglyNode* curr=slow;
            SinglyNode* tep=NULL;
            while(curr!=NULL)
            {   prev=tep;
                tep=curr;
                curr=curr->next;
                tep->next=prev;
            }
            slow=tep;

            SinglyNode*temp=head;
            SinglyNode*Last=slow;
            int flag=0;
            while(Last!=NULL)
            { 
                if(temp->number!=Last->number)
                {   flag=1;
                    cout<<"Linklist is not Palindrome...."<<endl;
                    break;

                }

                temp=temp->next;
                Last=Last->next;
            }
            if(flag==0) {
                cout<<"Linklist is Palindrome...."<<endl;
            }
            
            temp=head;
            head = slow;
            reverse();
            head=temp;
            //show();
        }

    }

};
///////////////////////// Doubly LINKLIST CLASS /////////////////////////////////////
class DoublyNode {
	int number;
	
	DoublyNode*head=NULL;
	DoublyNode*next;
	DoublyNode*prev;
	public :
	DoublyNode(){
	}
	void show()
    {   if(head==NULL)
        {   cout<<"NOTHING IN LINKLIST......"<<endl;
        }
        else {

            DoublyNode* temp=head;
            while(temp!=NULL)
            {   cout<<temp->number<<" ";
                temp=temp->next;
            }
        }
    }
	DoublyNode(int value){
		next=NULL;
		prev=NULL;
	}
	void addFirst(int value){
	
	DoublyNode*newnode= new DoublyNode(value);
	newnode->number=value;
	if(head==NULL)
	{
			head=newnode;
		cout<<endl<<"Add at First SUCCESSFULLY....."<<endl;}
	else{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		cout<<endl<<"Add at First SUCCESSFULLY....."<<endl;
	}
}
void addLast(int value){
DoublyNode * newnode = new DoublyNode(value);
newnode->number=value;
if(head==NULL)
{ head=newnode;
	cout<<endl<<"Add at Last SUCCESSFULLY....."<<endl;
}
else {
DoublyNode *temp =head;
while (temp->next != NULL)
{
temp =temp->next;
}
temp->next=newnode;
newnode->prev=temp;
	cout<<endl<<"Add at Last SUCCESSFULLY....."<<endl;
}
//show();
}
void deleteFirst()
    {
    	if(head==NULL)
        {   
		    cout<<" Linklist is empty ! Add Values First......."<<endl;
        }
        else 
		{
            DoublyNode * temp = head;
            head=temp->next;
            delete temp;
            cout<<endl<<" Delete sucessfully.."<<endl;
        }
	}
	void deleteLast()
	{
		if(head==NULL)
        {   
		    cout<<" Linklist is empty ! Add Values First......."<<endl;
        }
        else if(head->next == NULL) 
		{
			delete head;
            head=NULL;
            //tail=NULL;
            cout<<" Delete sucessfully.."<<endl;
        }
        else
		{
            DoublyNode* temp = head;
            while(temp->next->next!=NULL)
            {   
			    temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
            //tail=temp;
            cout<<" Deleted sucessfully.."<<endl;
        }
	}
	void insertat(int index,int newValue)
    {   if(head==NULL)
        {   
		    cout<<"Linklist does not Exist .... Please ADD something"<<endl<<endl;
        }
        else 
		{
            int valid=countNodes();
            if(index>=1&&index<=valid) {
                if(index==1)
                {   
				    DoublyNode::addFirst(newValue);
                }
                else 
				{
                   DoublyNode* newNode= new DoublyNode(newValue);
                    newNode->number=newValue;
                    newNode->next=NULL;
                    newNode->prev=NULL;
                    DoublyNode * temp = head;
                    for(int i=1; i<index-1; i++)
                    {
                        temp=temp->next;
                    }
                    newNode->next=temp->next;
                    newNode->prev=temp;
                    temp->next=newNode;
                    newNode->next->prev=newNode;
                    //show();
                }
            }
            else 
			{
                cout<<"Sorry ! index is not in our linklist ...."<<endl;
                cout<<"Your Index must be 1 to "<<valid<<endl;
            }
        }
    }
    void searchValue(int searchvalue)
    {   
	    if(head==NULL)
	    {
            cout<<"Kindly Add something to search"<<endl;
        }
        else
        {   
		    int found=0;
            DoublyNode *temp=head;
            while(temp!=NULL)
            {
                if(temp->number==searchvalue)
                {
                    cout<<"Number Found"<<endl;
                    found++;
                }
                temp=temp->next;
            }
            if(found==0)
            {  
			    cout<<"Sorry ! Number Not found "<<endl;
            }
        }
    }
    int countNodes()
    {   int counter=1;
    
        if(head==NULL)
        {   
		    counter=0;
            cout<<"Kindly ! Add Something First then Count "<<endl;
        }
        else {
            DoublyNode*temp=head;
            while(temp->next!=NULL)
            {   counter++;
                temp=temp->next;
            }
        }
        return counter;
    }
       void maximun() {
        if(head==NULL)
            cout<<"Kindly Add something "<<endl;
        else {

            DoublyNode*temp = head;
            int max=temp->number;
            while(temp!=NULL) {
                if(max<temp->number) {
                    max=temp->number;
                }
                temp=temp->next;
            }
            cout<<"Maximum value in this linklist is : "<<max<<endl;
        }
    }
    void average()
    {   if(head==NULL)
            cout<<"Kindly Add something First "<<endl;
        else 
		{
            float average;
            DoublyNode*temp=head;
            while(temp!=NULL)
            {   average+=temp->number;
                temp=temp->next;
            }
            average=(average/countNodes());
            cout<<"Average of our Linklist is : "<<average<<endl;
        }
    }
    void reverse()
    {   if(head==NULL)
            cout<<"Kindly Add something First "<<endl;
        else {
            DoublyNode* prev=NULL;
            DoublyNode* curr=head;
            DoublyNode* temp=NULL;

            while(prev!=NULL)
            {   
			    prev=temp;
                temp=curr;
                curr=curr->next;
                temp->next=prev;
            }
            head=temp;
           
show();
        }
    }

    void detectLoop() {
        int flag=0;
        if(head==NULL||head->next==NULL) 
		{
            cout<<"There is no loop in linklist ! if linklist is empty or only 1 Node......."<<endl;
        }
        else {
            DoublyNode * Slow =head;
            DoublyNode * Fast =head->next;
            while(Fast !=NULL && Fast->next !=NULL)
            {   if(Slow==Fast) {
                    cout<<"Loop Detected in this Linklist "<<endl;
                    flag++;
                }
                Slow=Slow->next;
                Fast=Fast->next->next;
            }
            if(flag==0) {
                cout<<"Loop Not Detected in this Linklist"<<endl;
            }
        }
    }

};
///////////////////////// CIRCULAR Singly LINKLIST CLASS /////////////////////////////////////
class circularSNode{
	circularSNode*head=NULL;
	int number;
	circularSNode*next;
	public :
	circularSNode(){
		
	}
	circularSNode(int value){
		next=NULL;
	}
	void show(){
		
      if(head==NULL)
        {   cout<<"NOTHING IN LINKLIST......"<<endl;
        }
        else {

            circularSNode* temp=head;
        
           do
            {   cout<<temp->number<<" ";
                temp=temp->next;
            }
             while(temp!=head);
        }
    		
	}
	void addFirst(int value){
		circularSNode*newnode=new circularSNode(value);
		newnode->number=value;
		if(head==NULL){
			head=newnode;
			newnode->next=head;
			cout<<endl<<"Add at First SUCCESSFULLY....."<<endl;
		
		}
		else {
			circularSNode*temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=head;
			head=newnode;
			cout<<endl<<"Add at First SUCCESSFULLY....."<<endl;
				show();
		}
	
	}
	void addLast(int value){
			circularSNode*newnode=new circularSNode(value);
		newnode->number=value;
		if(head==NULL)
        {  
		 cout<<"NO Node before ! First Node in LINKLIST......"<<endl;
             head=newnode;
			newnode->next=head;
			cout<<endl<<"Add at Last SUCCESSFULLY....."<<endl;
        }
        else{
        	circularSNode*temp=head;
        		while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=head;
        	cout<<endl<<"Add at Last SUCCESSFULLY....."<<endl;
		}
		show();
	}
	void deletefirst(){
		circularSNode*del=head;
		  if(head==NULL)
        {   cout<<" Linklist is empty ! Add Values First......."<<endl;
        }
        else if(head->next==head){
        	head=NULL;
        		delete del;
        	  cout<<endl<<" Delete sucessfully.."<<endl;
		}
        else {
        	circularSNode*temp=head;
        	
        	
        	while(temp->next!=head){
        		temp=temp->next;
			}
			
			head=head->next;
			temp->next=head;
			  cout<<endl<<" Delete sucessfully.."<<endl;
			//show();
			delete del;
		
			
	}
}
void deleteLast ()
    {    	circularSNode * temp = head;
	if(head==NULL)
        {   cout<<" Linklist is empty ! Add Values First......."<<endl;

        }
        else if(head->next==head) {
            head=NULL;
            delete temp;
            cout<<" Delete Last sucessfully.."<<endl;
        }
        else { 	
			
			circularSNode*prev=head;
		while(temp->next!=head){
        		prev=temp;
				temp=temp->next;
			}
			prev->next=head;
			
			delete temp;
			cout<<endl<<" Delete Last sucessfully.."<<endl;
			show();
		}
		}

	void insertat(int index,int newValue)
    {   if(head==NULL)
        {   
		    cout<<"Linklist does not Exist .... Please ADD something"<<endl<<endl;
        }
        else 
		{
            int valid=countNodes();
            if(index>=1&&index<=valid) {
                if(index==1)
                {   
				    addFirst(newValue);
                }
                else 
				{ circularSNode* newNode= new circularSNode(newValue);
                    newNode->number=newValue;
                    
                   circularSNode * temp = head;
                    for(int i=1; i<index-1; i++)
                    {
                        temp=temp->next;
                    }
                     newNode->next=temp->next;
                    temp->next=newNode;
                    
                }
                show();
            }
            else 
			{
                cout<<"Sorry ! index is not in our linklist ...."<<endl;
                cout<<"Your Index must be 1 to "<<valid<<endl;
            }
        }
    }
	 int countNodes()
    {   int counter=1;
    
        if(head==NULL)
        {   
		    counter=0;
            cout<<"Kindly ! Add Something First then Count "<<endl;
        }
        else {
            circularSNode*temp=head;
            while(temp->next!=head)
			   {   counter++;
                temp=temp->next;
            }
			
         
        }
        return counter;
    }
    void searchValue(int searchvalue)
    {   if(head==NULL)
            cout<<"Kindly Add something to search"<<endl;
        else
        {   int found=0;
            circularSNode *temp=head;

           do
            {
                if(temp->number==searchvalue)
                {
                    cout<<"Number Found"<<endl;
                    found++;

                }
                temp=temp->next;
            }
             while(temp!=head);
            if(found==0)
            {   cout<<"Sorry ! Number Not found "<<endl;
            }
        }
    }
      void maximun() {
        if(head==NULL)
            cout<<"Kindly Add something "<<endl;
        else {

            circularSNode*temp=head;
            int max=temp->number;
             do {
                if(max<temp->number) {
                    max=temp->number;
                }
                temp=temp->next;
            }
            while(temp!=head);
            cout<<"Maximun value in this linklist is : "<<max<<endl;
        }
    }
       void reverse()
    {   if(head==NULL)
            cout<<"Kindly Add something First "<<endl;
        else {
            circularSNode* prev=NULL;
            circularSNode* curr=head;
            circularSNode* temp=NULL;

            do
            {   prev=temp;
                temp=curr;
                curr=curr->next;
                temp->next=prev;
 }
 while(curr!=head);
           head->next=temp;
		    head=temp;
            
show();
        }
    }
    void average()
    {   if(head==NULL)
            cout<<"Kindly Add something First "<<endl;
        else {
            float average;
          circularSNode*temp=head;
             do
            {   average+=temp->number;
                temp=temp->next;
            }
            while(temp!=head);
            average=(average/countNodes());
            cout<<"Average of our Linklist is : "<<average<<endl;
        }
    }
    void detectLoop() {
        int flag=0;
        if(head==NULL||head->next==head) {
            cout<<"There is no loop in linklist ! if linklist is empty or only 1 Node......."<<endl;

        }
        else {
            circularSNode * Slow =head;
             circularSNode * Fast =head->next;
           do
            {   if(Slow==Fast) {
                    cout<<"Loop Detected in this Linklist "<<endl;
                    flag++;
                }
                Slow=Slow->next;
                Fast=Fast->next->next;
            }
             while(Fast !=head && Fast->next !=head); 

            if(flag==0) {
                cout<<"Loop Not Detected in this Linklist"<<endl;
            }
        }
    }
};
    
///////////////////////// CIRCULAR Doubly LINKLIST CLASS /////////////////////////////////////
class circularDNode {
    circularDNode* head = NULL;
    int number;
    circularDNode* next;
    circularDNode* prev; // Add prev pointer

public:
    circularDNode() {}

    circularDNode(int value) {
        next = NULL;
        prev = NULL; // Initialize prev pointer
    }

    ~circularDNode() { // Destructor to deallocate memory
        circularDNode* temp = head;
	    while (head != NULL) {
           
            head = head->next;
            delete temp;
        }}
	void show(){
		
      if(head==NULL)
        {   cout<<"NOTHING IN LINKLIST......"<<endl;
        }
        else {
            circularDNode* temp=head;
           do
            {   cout<<temp->number<<" ";
                temp=temp->next;
            }
            while(temp!=head);
        }		
	}
	void addFirst(int value){
		circularDNode*newnode=new circularDNode(value);
		newnode->number=value;
		if(head==NULL){
			head=newnode;
			newnode->next=head;
			cout<<endl<<"Add at First SUCCESSFULLY....."<<endl;
		}
		else {
			circularDNode*temp=head;
			circularDNode*prev;
			newnode->next=head;
	    	head->prev=newnode;
		    head=newnode;
			cout<<endl<<"Add at First SUCCESSFULLY....."<<endl;
			show();
		}
	
	}
	void addLast(int value){
			circularDNode*newnode=new circularDNode(value);
		newnode->number=value;
		if(head==NULL)
        {  
		 cout<<"NO Node before !"<<endl;
            head=newnode;
			cout<<endl<<"Add at Last SUCCESSFULLY....."<<endl;
        }
        else{
        	circularDNode*temp=head;
        		while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next=head;
        	cout<<endl<<"Add at Last SUCCESSFULLY....."<<endl;
		}
		show();
	}
	void deletefirst(){
		  if(head==NULL)
        {   cout<<" Linklist is already empty ! "<<endl;
        }
        else if(head->next==head){
        	head=NULL;
        	  cout<<endl<<" Delete sucessfully.."<<endl;
		}
        else {
        	circularDNode*temp=head;
            head=temp->next;
			delete temp;
			  cout<<endl<<" Delete sucessfully.."<<endl;
			//show();
	}
}
void deleteLast ()
    {    	circularDNode * temp = head;
	if(head==NULL)
        {   cout<<" Linklist is empty ! Add Values First......."<<endl;

        }
        else if(head->next==head) {
            head=NULL;
            delete temp;
            cout<<" Delete Last sucessfully.."<<endl;
        }
        else { 	
			
			circularDNode*prev=head;
		while(temp->next->next!=head){
        		prev=temp;
				temp=temp->next;
			}
			
			delete temp->next;
			temp->next=head;
			cout<<endl<<" Delete Last sucessfully.."<<endl;
			show();
		}
		}

	void insertat(int index,int newValue)
    {   if(head==NULL)
        {   
		    cout<<"Linklist does not Exist .... Please ADD something"<<endl<<endl;
        }
        else 
		{
            int valid=countNodes();
            if(index>=1&&index<=valid) {
                if(index==1)
                {   
				    addFirst(newValue);
                }
                else 
				{ circularDNode* newNode= new circularDNode(newValue);
				circularDNode*prev;
                    newNode->number=newValue;
                    newNode->next=NULL;
                    newNode->prev=NULL;
                   circularDNode * temp = head;
                    for(int i=1; i<index-1; i++)
                    {
                        temp=temp->next;
                    }
                     newNode->next=temp->next;
                     newNode->prev=temp;
                    temp->next=newNode;  
					newNode->next->prev=newNode;               
                }
                show();
            }
            else 
			{
                cout<<"Sorry ! index is not in our linklist ...."<<endl;
                cout<<"Your Index must be 1 to "<<valid<<endl;
            }
        }
    }
	 int countNodes()
    {   int counter=1;
    
        if(head==NULL)
        {   
		    counter=0;
            cout<<"Kindly ! Add Something First then Count "<<endl;
        }
        else {
            circularDNode*temp=head;
            while(temp->next!=head)
			   {   counter++;
                temp=temp->next;
            }
        }
        return counter;
    }
    void searchValue(int searchvalue)
    {   if(head==NULL)
            cout<<"Kindly Add something to search"<<endl;
        else
        {   int found=0;
            circularDNode *temp=head;
           do
            {
                if(temp->number==searchvalue)
                {
                    cout<<"Number Found"<<endl;
                    found++;
                }
                temp=temp->next;
            }
             while(temp!=head);
            if(found==0)
            {   
			    cout<<"Sorry ! Number Not found "<<endl;
            }
        }
    }
      void maximum() {
        if(head==NULL)
            cout<<"Kindly Add something "<<endl;
        else {
            circularDNode*temp=head;
            int max=temp->number;
             do {
                if(max<temp->number) {
                    max=temp->number;
                }
                temp=temp->next;
            }
            while(temp!=head);
            cout<<"Maximun value in this linklist is : "<<max<<endl;
        }
    }
       void reverse()
    {   if(head==NULL)
            cout<<"Kindly Add something First "<<endl;
        else {
            circularDNode* prev=NULL;
            circularDNode* curr=head;
            circularDNode* next;
            do
            {   
			    next=curr->next;
			    curr->next=prev;
			    curr->prev=next;
			    prev=curr;
			    curr=next;
            } while(curr!=head);
            head=prev;  
show();
        }
    }
    void average()
    {   if(head==NULL)
            cout<<"Kindly Add something First "<<endl;
        else {
            float average;
          circularDNode*temp=head;
             do
            {   average+=temp->number;
                temp=temp->next;
            }
            while(temp!=head);
            average=(average/countNodes());
            cout<<"Average of our Linklist is : "<<average<<endl;
        }
    }
    void detectLoop() {
        int flag=0;
        if(head==NULL||head->next==head) {
            cout<<"There is no loop in linklist ! if linklist is empty or only 1 Node......."<<endl;

        }
        else {
            circularDNode * Slow =head;
             circularDNode * Fast =head->next;
           do
            {   if(Slow==Fast) {
                    cout<<"Loop Detected in this Linklist "<<endl;
                    flag++;
                }
                Slow=Slow->next;
                Fast=Fast->next->next;
            }
             while(Fast !=head && Fast->next !=head); 

            if(flag==0) {
                cout<<"Loop Not Detected in this Linklist"<<endl;
            }
        }
    }	
};

int main()
 {
    system("cls");
    
    
        int choice;
        int innerChoice;
        int value;
        linklist L1;
        SinglyNode S1;
        DoublyNode D1;
        circularSNode C1;
         circularDNode CD;
firstloop :
        cout << endl << " (()).....................................LinkList............................................(())" << endl;

        choice = L1.mainlist();

        switch (choice) {
            case 1:
                system("cls");
                cout << endl << " ...............................Singly LinkList.........................................." << endl;
                while (true) {
                    innerChoice = L1.functionList(choice);
                    switch (innerChoice) {
            case 1:
                cout<<endl<<"Enter the value you want to add at First in Singly Linklist :";
                cin>>value;
                S1.addFirst(value);
                system("pause");
                cout<<endl;
                break;

            case 2:
                cout<<endl<<"Enter the value you want to add at Last  :";
                cin>>value;
                S1.addLast(value);
                system("pause");
                cout<<endl;
                break;
            case 3:
                S1.deleteFirst();
                system("pause");
                cout<<endl;
                break;
            case 4:
                S1.deleteLast();

                system("pause");
                break;
            case 5:
                cout<<endl<<"Enter the value you want to add   :";
                cin>>value;
                cout<<endl;

                int index;
                cout<<endl<<"Enter the index where you insert node :";
                cin>>index;
                S1.insertat(index,value);
                system("pause");
                break;
            case 6:
                cout<<endl<<"Enter the value you want to search :";
                cin>>value;
                S1.searchValue(value);
                system("pause");
                break;
            case 7:
                cout<<"There are "<<S1.countNodes()<<" Nodes in this Linklist "<<endl;
                system("pause");
                break;
            case 8:
                S1.maximum();
                system("pause");

                break;
            case 9:
                S1.average();
                system("pause");
                break;
            case 10:
                S1.reverse();
                system("pause");
                break;
            case 11:
                S1.detectLoop();
                system("pause");
                break;
            case 12:
                S1.palindrome();
                system("pause");
                break;
            case 13 :
            	goto firstloop;
                break;
            }
        }
        break;
     case 2:
                system("cls");
                cout << endl << " ...............................Doubly LinkList.........................................." << endl;
                while (true) {
                    innerChoice = L1.functionList(choice);
                    switch (innerChoice) {
        case 1:
cout<<endl<<"Enter the value you want to add at First in Doubly Linklist :";
                cin>>value;
                D1.addFirst(value);
              
                 system("pause");
                  cout<<endl;
            break;
        case 2:
        	  cout<<endl<<"Enter the value you want to add at Last in Doubly Linklist : ";
                cin>>value;
                D1.addLast(value);
                system("pause");
                cout<<endl;
            break;
        case 3:
        	 D1.deleteFirst();
                system("pause");
                cout<<endl;
            break;
        case 4:
        	D1.deleteLast();
        	system("pause");
            break;
        case 5:
        	 cout<<endl<<"Enter the value you want to add   :";
                cin>>value;
                cout<<endl;

                int index;
                cout<<endl<<"Enter the index where you insert node :";
                cin>>index;
                D1.insertat(index,value);
                system("pause");
            break;
        case 6:
        	cout<<endl<<"Enter the value you want to search :";
                cin>>value;
                D1.searchValue(value);
                system("pause");
            break;
        case 7:
        	 cout<<"There are "<<D1.countNodes()<<" Nodes in this Linklist "<<endl;
                system("pause");
            break;
        case 8:
        	D1.maximun();
        	system("pause");
            break;
        case 9:
        	D1.average();
        	system("pause");
            break;
        case 10:
        	D1.reverse();
        	 system("pause");
                cout<<endl;
            break;
        case 11:
        	D1.detectLoop();
            break;
        case 12 :
        	goto firstloop;
            break;
        }
    }
        break;
    case 3:
                system("cls");
                cout << endl << " ...............................Circular Singly LinkList.........................................." << endl;
                while (true) {
                    innerChoice = L1.functionList(choice);
                    switch (innerChoice) {
        case 1:
        	    cout<<endl<<"Enter the value you want to add at First in Circular Singly Linklist : ";
                cin>>value;
                C1.addFirst(value);
                system("pause");
                cout<<endl;
            break;
        case 2:
        	cout<<endl<<"Enter the value you want to add at Last in Circular Singly Linklist : ";
                cin>>value;
                C1.addLast(value);
                system("pause");
                cout<<endl;
            break;
        case 3:
        	C1.deletefirst();
        	system("pause");
                cout<<endl;
            break;
        case 4:
        	C1.deleteLast();
        	system("pause");
                cout<<endl;
            break;
        case 5:
        	cout<<endl<<"Enter the value you want to add   :";
                cin>>value;
                cout<<endl;

                int index;
                cout<<endl<<"Enter the index where you insert node :";
                cin>>index;
                C1.insertat(index,value);
                system("pause");
            break;
        case 6:
        	cout<<endl<<"Enter the value you want to search :";
                cin>>value;
                
                C1.searchValue(	value);
                system("pause");
            break;
        case 7:
        	cout<<"There are "<<C1.countNodes()<<" Nodes in this Linklist "<<endl;
                system("pause");
            break;
        case 8:
        	C1.maximun();
                system("pause");
            break;
        case 9:
        	  C1.average();
                system("pause");
            break;
        case 10:
        	C1.reverse();
        	system("pause");
            break;
        case 11:
        	   C1.detectLoop();
                system("pause");
            break;
        case 12 :
        	goto firstloop;
            break;
        }
    }
        break;
     case 4:
                system("cls");
                cout << endl << " ...............................Circular Doubly LinkList.........................................." << endl;
                while (true) {
                    innerChoice = L1.functionList(choice);
                    switch (innerChoice) {
                        case 1:
                            cout << endl << "Enter the value you want to add at First in Circular Singly Linklist : ";
                            cin >> value;
                            CD.addFirst(value);
                            system("pause");
                            cout << endl;
                            break;
                        case 2:
                            cout << endl << "Enter the value you want to add at Last in Circular Singly Linklist : ";
                            cin >> value;
                            CD.addLast(value);
                            system("pause");
                            cout << endl;
                            break;
                        case 3:
                            CD.deletefirst();
                            system("pause");
                            cout << endl;
                            break;
                        case 4:
                            CD.deleteLast();
                            system("pause");
                            cout << endl;
                            break;
                         case 5:
        	              cout<<endl<<"Enter the value you want to add   :";
                            cin>>value;
                           cout<<endl;

                            int index;
                            cout<<endl<<"Enter the index where you insert node :";
                           cin>>index;
                            CD.insertat(index,value);
                            system("pause");
                              break;
                              case 6:
        	cout<<endl<<"Enter the value you want to search :";
                cin>>value;
                CD.searchValue(	value);
                system("pause");
            break;
        case 7:
        		cout<<"There are "<<CD.countNodes()<<" Nodes in this Linklist "<<endl;
                system("pause");
            break;
        case 8:
        		CD.maximum();
                system("pause");
            break;
        case 9:
        	CD.average();
        	system("pause");
            break;
        case 10:
        	CD.reverse();
        	system("pause");
            break;
        case 11:
        	CD.detectLoop();
        	system("pause");
            break;
        case 12 :
        	goto firstloop;
            break;
        }
    }
     break;
      }
    
     return 0;
 }
    
