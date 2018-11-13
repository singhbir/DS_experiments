    #include<iostream>
    using namespace std;

    class convert
    {
        char a[20];
        int top;
    public:
        convert()
        {
        top=-1;
        }
        void push(int x)
        {
            a[++top]=x;
        }
        char pop()
        {
            return a[top--];
        }
        int priority(char p)
        {
            if(p=='(' )
                return 0;
            else if(p=='+'||p=='-')
                return 1;
            else if(p=='*'|| p=='/')
                return 2;
            else if(p=='^')
                return 3;
        }

    void in_po(char exp[20])
    {
        char *e;
        char x;
        e=exp;
        while(*e!='\0')
        {
            if(isalnum(*e))
            {
                cout<<*e;
            }
            else if(*e=='(')
            {
                push(*e);
            }
            else if(*e==')')
            {
                while((x=pop())!='(')
                cout<<x;
            }
            else
            {
                while(priority(a[top])>=priority(*e))
                    cout<<pop();
                push(*e);
            }
            e++;
        }
        while(top!=-1)
        {
            x=pop();
            cout<<x;
        }
    }
};

class s1
    {
        public:
        char a[20];
        int top;
        s1()
        {
        top=-1;
        }
        void push(int x)
        {
            a[++top]=x;
        }
        int pop()
        {
            return a[top--];
        }
    void in_po(char exp[20])
    {
        char *e;
        char x;
        int num;
        e=exp;
        while(*e!='\0')
        {
            if(isalnum(*e))
            {
                num=*e-48;
                push(num);
            }
            else
            {
                int a=pop();
                int b=pop();
                int c;
                switch(*e)
                {
                    case '+':
                        c=a+b;
                        push(c);
                        break;
                    case '-':
                        c=a-b;
                        push(c);
                        break;
                    case '/':
                        c=a/b;
                        push(c);
                        break;
                    case '*':
                        c=a*b;
                        push(c);
                        break;
                    case '^':
                        c=a^b;
                        push(c);
                        break;
                }
            }
            e++;
        }
        while(top!=-1)
        {
            cout<<pop();
        }
    }
};

    int main()
    {
        int ch;
        cout<<"Enter choice:\n1 for Infix to postfix conversion\n2 for Postfix Evaluation\n";
        cin>>ch;
        if(ch==1)
        {
            convert r;
            char ss[20];
            cin>>ss;
            r.in_po(ss);
        }
        else if(ch==2)
        {
            s1 r;
            char ss[20];
            cin>>ss;
            r.in_po(ss);
        }
    }

