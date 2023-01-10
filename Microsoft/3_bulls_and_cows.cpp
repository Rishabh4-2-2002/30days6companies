class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        int cow=0;
        string ans="";
        unordered_map<int,int> umap;
        unordered_map<int,int> umap2;

        for(int i=0;i<secret.size();i++)
        {
            bool con1=true,con2=true;
            // cout<<secret[i]<<" vs "<<guess[i]<<endl;
            if(secret[i]==guess[i])
            {
                cout<<" -> equal "<<endl;
                bull++;
            }else{
                if(umap.find(guess[i]) != umap.end() && umap[guess[i]] >0){
                        // cout<<endl<<" guess in first map"<<endl;
                        umap[guess[i]]--;
                        cow++;
                        con1=false;
                }else{
                    umap2[guess[i]]++;
                }
                if(umap2.find(secret[i]) != umap2.end() && umap2[secret[i]] >0){
                    // cout<<endl<<" secret in second map"<<endl;
                    cow++;
                    umap2[secret[i]]--;
                }else{
                    // cout<<"just umapping"<<endl;   
                    umap[secret[i]]++;
                }
            }
        }
        cout<<cow<<endl;
        ans+=to_string(bull);
        ans+='A';
        ans+=to_string(cow);
        ans+='B';
        return ans;
    }
};