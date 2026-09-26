class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<s.size();){
            string ans="";
            int j=0;
            if(s[i]=='('){
                j=i;
               j++;
                while(s[j]!=')'){
                   ans+=s[j];
                   j++;
                }
                
                int len=j-i+1;
            if(mp.find(ans)!=mp.end()){
               string val=mp[ans];
               s.replace(i,len,val);
               i=i+val.size();
            }
            else{
                s.replace(i,len,"?");
                i++;
            }

            
            }
            else{
                i++;
            }
           
           
            

        }
        return s;
    }
};