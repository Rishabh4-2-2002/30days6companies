class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //op solution
        map<pair<int,int>,int> umap;

        for(auto itr : rectangles)
        {
            umap[{itr[0],itr[1]}]++;
            umap[{itr[2],itr[3]}]++;
            umap[{itr[0],itr[3]}]--;
            umap[{itr[2],itr[1]}]--;
        }
        //now traversing to see if any is false
        int num_sides=0;
        for(auto itr = umap.begin();itr!=umap.end();itr++)
        {
            if(itr->second!=0)
            {
                if(abs(itr->second) != 1)    return false;
                else num_sides++;
            }
        }
        return num_sides==4;
    }
};