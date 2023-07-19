#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
string s[100];
vector<int>qt,it,bmp,bmw;
vector<double>pr;
int i=0,c=0,bmc=0,n0,pc,mn=0,mq=0;
double sum=0;
void addmedicine();
void readdmedicine();
void ml();
void ml1();
void Search();
void bm();
void tb();
void deletemedicine();

int main()
{
    cout<<"1. MEDICINE LIST  "<<endl;
    cout<<"2. ADD MEDICINE  "<<endl;
    cout<<"3. RE-ADD MEDICINE"<<endl;
    cout<<"4. DELETE MEDICINE  "<<endl;
    cout<<"5. SEARCH MEDICINE  "<<endl;
    cout<<"6. BUY MEDICINE "<<endl;
    cout<<"7. CHECK BILL "<<endl;
    cout<<"WHAT DO YOU WANT?"<<endl;
    string n;
    cin>>n;
    system("cls");
    if(n[0]=='1')
    {
        ml();
    }
    if(n[0]=='2')
    {
        addmedicine();
    }
    if(n[0]=='3')
    {
        readdmedicine();
    }
    if(n[0]=='4')
    {

        deletemedicine();



        i++;
        int mo;
        cout<<"Back to main menu press 1"<<endl;
        cin>>mo;
        system("cls");
        if(mo==1)
            main();



    }
    if(n[0]=='5')
    {
        Search();
    }
    if(n[0]=='6')
    {
        bm();
    }
    if(n[0]=='7')
        tb();

    else
    {
        cout<<"Wrong press(please press 1-7)"<<endl;
        main();
    }
}
void addmedicine()
{
    int tm,qt1,mo;
    double pr1;
    cout<<"How many madicines "<<endl;
    cin>>tm;

    while(tm--)
    {
        cout<<"Enter Medicine Name :"<<endl;
        cin>>s[i];
        cout<<"Quantities :"<<endl;
        cin>>qt1;
        cout<<"Price per pcs :"<<endl;
        cin>>pr1;
        qt.push_back(qt1);
        pr.push_back(pr1);
        if(c>0)
            it.push_back(i+2);
        else
            it.push_back(i+1);

        i++;
        c=0;
    }
    c=0;
    cout<<"Back to main menu press 1"<<endl;
    cin>>mo;
    system("cls");
    while(mo!=1)
    {
        cout<<"opps! Wrong press(press only 1)"<<endl;
        cin>>mo;
    }
    main();
}

void ml1()
{
    cout<<"#Medicine Name#"<<"\t"<<"#Quantities(pcs)#"<<"\t"<<"#Prices(per pcs)#"<<endl;
    for(int j=0; j<i; j++)
    {
        cout<<s[j]<<"\t"<<"\t"<<qt[j]<<"\t"<<"\t"<<"\t"<<pr[j]<<endl;
    }




}
void ml()
{
    cout<<"#Medicine Name#"<<"\t"<<"#Quantities(pcs)#"<<"\t"<<"#Prices(per pcs)#"<<endl;
    for(int j=0; j<i; j++)
    {
        cout<<s[j]<<"\t"<<"\t"<<qt[j]<<"\t"<<"\t"<<"\t"<<pr[j]<<endl;
    }
    int mo;
    cout<<"Back to main menu press 1"<<endl;
    cin>>mo;
    while(mo!=1)
    {
        cout<<"opps! Wrong press(press only 1)"<<endl;
        cin>>mo;
    }
    main();


}
void Search()
{
    int m=0;
    cout<<"ENTER MEDICINE NAME"<<endl;
    string se;
    cin>>se;
    for(int r=0; r<i; r++)
    {
        if(se==s[r])
        {
            m=1;
            cout<<"Yes Found"<<endl;
             cout<<"#Medicine Name#"<<"\t"<<"#Quantities(pcs)#"<<"\t"<<"#Prices(per pcs)#"<<endl;
           cout<<s[r]<<"\t"<<"\t"<<qt[r]<<"\t"<<"\t"<<"\t"<<pr[r]<<endl;
            break;
        }
    }
    if(m==0)
    {
        cout<<"Sorry!!! Not Found"<<endl;
    }
    int mo;
    cout<<"Back to main menu press 1"<<endl;
    cin>>mo;
    system("cls");
     while(mo!=1)
    {
        cout<<"opps! Wrong press(press only 1)"<<endl;
        cin>>mo;
    }
    main();
}
void Search1()
{

    cout<<"ENTER MEDICINE NAME"<<endl;
    string se;
    cin>>se;
    for(int r=0; r<i; r++)
    {

        if(se==s[r])
        {
            mq=1;
            n0=r;

            break;
        }
    }
    if(mq==0)
    {
        cout<<"Sorry!!! Not Found"<<endl;
    }

}
void readdmedicine()
{
    int u,t;
    cout<<"How many medicine"<<endl;
    cin>>t;
    while(t--){
    Search1();
    if(mq==1)
    {
    cout<<"How many"<<endl;
    cin>>u;
    qt[n0]+=u;
    }
    else if(mq==0)
    {
        t=0;
        mq=0;


    }
    }
     int mo;
    cout<<"Back to main menu press 1"<<endl;
    cin>>mo;
    system("cls");
    while(mo!=1)
    {
        cout<<"opps! Wrong press(press only 1)"<<endl;
        cin>>mo;
    }
    main();

}
void deletemedicine()
{
    c++;
    ml1();
     Search1();
    int mdt1;
     mdt1=n0;
    for(int y=mdt1; y<=i-2; y++)
    {
        s[y]=s[y+1];
    }

    i=i-2;
    qt.erase(qt.begin()+mdt1);
    pr.erase(pr.begin()+mdt1);
    it.erase(it.begin()+mdt1);



}
void bm()
{
    ml1();
    int b=1;
    while(b!=0)
    {

        Search1();
        bmp.push_back(n0);
        cout<<"How many"<<endl;
        cin>>pc;
        if(pc<=qt[n0]){

        bmw.push_back(pc);
        qt[n0] = qt[n0]-pc;
        bmc++;
        cout<<"for complete purchase press 0 otherwise 1"<<endl;
        cin>>b;}
        else if(pc>qt[n0])
        {
            system("cls");
            cout<<"NOT AVAILABLE"<<endl;

            bm();
        }



    }
    int mo;
    cout<<"Back to main menu press 1"<<endl;
    cin>>mo;
    system("cls");
    while(mo!=1)
    {
        cout<<"opps! Wrong press(press only 1)"<<endl;
        cin>>mo;
    }
    main();


}
void tb()
{

    for(int b=0; b<bmc; b++)
    {
        sum+=bmw[b]*pr[bmp[b]];
        cout<<s[bmp[b]]<<"\t"<<bmw[b]<<"\t"<<bmw[b]*pr[bmp[b]]<<endl;
    }

    cout<<"Total bill"<<endl<<sum<<endl;
    sum=0;

    int mo;
    cout<<"Back to main menu press 1"<<endl;
    cin>>mo;
    system("cls");
     while(mo!=1)
    {
        cout<<"opps! Wrong press(press only 1)"<<endl;
        cin>>mo;
    }
    main();
}

