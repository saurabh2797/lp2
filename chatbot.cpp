#include<bits/stdc++.h>
using namespace std;

class chatBot{

    public:
    map<string,vector<string>> rules;

    chatBot()
    {
        intiallizeRules();
    }

 string processedRequest(string req){
        string processedReq;
        for(int i=0;i<req.size();i++)
        {
            if(req[i]!=' ' && !isdigit(req[i])){
                processedReq+=req[i];
            }
        }
        return processedReq;
    }
      void intiallizeRules(){ 
        rules["hello"]=vector<string>{"hi, how can i help you?","hey there", "hello,how are you?"};
        rules["howareyou"]=vector<string>{"amazing , how are you","i am good", "fantastic, what about you?"};
        rules["good"]=vector<string>{"ok, how can i help you?","nice"};
        rules["howcanicontactyouremployee"]=vector<string>{"yeah, here is there mail\n xzy@fix.com","here is the contact details:\n call:7058613042 \n email:xyz@fix.com"};
        rules["whatisofficeaddress"]=vector<string>{"202,surya complex, Wakad, Pune"};
        rules["whataretheservicesyouprovide"]=vector<string>{"we are srvice based company and we will consult you for how u can grow your buisness 10 times more faster.......to the moon"};
    }
   

    bool isValidResponse(string req){
        if(rules.find(req)==rules.end()){
            return false;
        }
        return true;
    }

    string getResponse(string req){
        if(req=="bye")
            exit(0);

        string finalReq = processedRequest(req);


        if(isValidResponse(finalReq))
        {
            int n = rules[finalReq].size();
            int rndm = rand()%n;
            return rules[finalReq][rndm];
        }    

        return "Sorry,I can't understand.";
    }

    };

int main()
{

    chatBot bot;
    cout<<"Hello, this is Jarvis here to assist you..."<<endl;
    string response;
    while (true)
    {
        cout<<"User : ";
        getline(cin,response);
        cout<<bot.getResponse(response)<<endl;
    }
    

}    
