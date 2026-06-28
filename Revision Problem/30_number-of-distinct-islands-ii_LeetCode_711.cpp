// google amazon meta
/*
Hard
Topics
conpanies icon
Companies
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

Return the number of distinct islands.

 

Example 1:


Input: grid = [[1,1,0,0,0],[1,0,0,0,0],[0,0,0,0,1],[0,0,0,1,1]]
Output: 1
Explanation: The two islands are considered the same because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.
Example 2:


Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
 
Seen this question in a real interview before?
1/6
Yes
No
Accepted
14,403/26K
Acceptance Rate
55.5%
  */
class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int,int>>& shape){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 || vis[i][j]) return;
        vis[i][j] = true;
        shape.push_back({i, j});
        for(auto& dir : dirs)
            dfs(i+dir[0], j+dir[1], grid, shape);
    }
    
    // 8 transformations generate karo
    vector<pair<int,int>> normalize(vector<pair<int,int>> shape){
        vector<vector<pair<int,int>>> transforms(8, vector<pair<int,int>>(shape.size()));
        
        for(int k = 0; k < shape.size(); k++){
            int x = shape[k].first, y = shape[k].second;
            transforms[0][k] = {x, y};
            transforms[1][k] = {x, -y};
            transforms[2][k] = {-x, y};
            transforms[3][k] = {-x, -y};
            transforms[4][k] = {y, x};
            transforms[5][k] = {y, -x};
            transforms[6][k] = {-y, -x};
            transforms[7][k] = {-y,x};
        }
        
        // Har transform ko origin shift karke sort karo
        for(auto& t : transforms){
            sort(t.begin(), t.end());
            int minX = t[0].first, minY = t[0].second;
            for(auto& p : t){
                minX = min(minX, p.first);
                minY = min(minY, p.second);
            }
            for(auto& p : t){
                p.first -= minX;
                p.second -= minY;
            }
            sort(t.begin(), t.end());
        }
        
        // Lexicographically smallest canonical form return karo
        // matlab external transform ko sort karne ne liye
        return *min_element(transforms.begin(), transforms.end());
    }
    
    int numDistinctIslands2(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        set<vector<pair<int,int>>> islands;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int,int>> shape;
                    dfs(i, j, grid, shape);
                    islands.insert(normalize(shape));  // ✅ canonical form insert
                }
            }
        }
        return islands.size();
    }
};

// explanantion
/*
ORIGINAL        90° Rotation      180° Rotation    270° Rotation
(x, y)          (y, -x)           (-x, -y)         (-y, x)

1 0             1 1 1             1 1              0 0 1
1 0             0 0 1             0 1              1 1 1
1 1                               0 1

REFLECT L-R     REFLECT U-D       TRANSPOSE        ANTI-TRANSPOSE
(x, -y)         (-x, y)           (y, x)           (-y, -x)

0 1             1 1               1 1 1            1 0 0
0 1             0 1               0 0 1            1 1 1
1 1             0 1
*/

/*
270° Rotation formula: (-y, x)
Original coordinates: (0,0),(1,0),(2,0),(2,1)
(x,y) → (-y, x)

(0,0) → (0,  0)
(1,0) → (0,  1)
(2,0) → (0,  2)
(2,1) → (-1, 2)
Normalize karo (minX = -1):
(0,0),(0,1),(0,2),(-1,2)
→ (1,0),(1,1),(1,2),(0,2)

0 0 1
1 1 1

Tera doubt — (x,-y) vs (-y,x):
(x, -y)  →  LEFT-RIGHT REFLECTION  (column flip)
(-y,  x)  →  270° ROTATION          (geometric rotation)
Dono alag operations hain:
(2,1) pe:
(x,-y)  → (2,-1)  →  normalize → reflect shape
(-y,x)  → (-1,2)  →  normalize → rotated shape

Rotation ka sahi formula yaad karne ka trick:
90°  CW: (x,y) → (y,-x)
180°   : (x,y) → (-x,-y)
270° CW: (x,y) → (-y,x)   ← 90° ko do baar apply karo
Verify:
90°  → (y,-x)
270° → 90° ko 3 baar:
(x,y) → (y,-x) → (-x,-y) → (-y,x) ✅
*/

/*
Step 1: Pehla sort kyun?
cppsort(t.begin(), t.end());
int minX = t[0].first, minY = t[0].second;
Pehle sort karne ke baad t[0] smallest element hoga — but yeh galat hai actually! MinX aur minY alag alag ho sakte hain:
Coordinates: (0,2), (-1,0), (0,1)
Sort karne ke baad: (-1,0), (0,1), (0,2)
t[0] = (-1,0) → minX=-1, minY=0  ✅ minX sahi hai
                              ❌ minY=0 sahi nahi, actual minY=0 hai yahan but always true nahi
Isliye loop se minX aur minY alag dhundha:
cppfor(auto& p : t){
    minX = min(minX, p.first);   // sabse chota row
    minY = min(minY, p.second);  // sabse chota column
}

Step 2: Origin shift
cppfor(auto& p : t){
    p.first  -= minX;   // sab rows shift karo
    p.second -= minY;   // sab cols shift karo
}
Before:  (-1,2), (0,0), (0,1)
minX=-1, minY=0
After:   (0,2),  (1,0), (1,1)  ← sab positive, (0,0) se start ✅

Step 3: Doosra sort
cppsort(t.begin(), t.end());
Origin shift ke baad order badal sakta hai — toh dobara sort:
Before sort: (0,2), (1,0), (1,1)
After sort:  (0,2), (1,0), (1,1)  ← compare karne layak

Step 4: min_element
cppreturn *min_element(transforms.begin(), transforms.end());
8 transforms mein se lexicographically smallest choose karo:
Transform 0: [(0,0),(0,1),(0,2),(1,0)]
Transform 1: [(0,0),(1,0),(1,1),(1,2)]
Transform 2: [(0,0),(0,1),(1,0),(1,1)]
...

min → [(0,0),(0,1),(0,2),(1,0)]  ✅ Canonical form

Puri baat ek line mein:
8 shapes → sab (0,0) se start karo → sort karo → 
sabse chota choose karo = unique fingerprint of island ✅

Kyun subtract karte hain?
Goal: Har shape ko (0,0) se start karo — taaki comparison possible ho.

Example:
Do alag jagah same shape hai:
Island 1:          Island 2:
. . . .            . . 1 .
. 1 . .            . . 1 .
. 1 . .            . . 1 1
. 1 1 .
Island 1 coords:   Island 2 coords:
(1,1)              (0,2)
(2,1)              (1,2)
(3,1)              (2,2)
(3,2)              (2,3)
Directly compare karo → alag lagte hain ❌

Subtract karo minX aur minY:
Island 1:          Island 2:
minX=1, minY=1     minX=0, minY=2

(1-1, 1-1)=(0,0)   (0-0, 2-2)=(0,0)
(2-1, 1-1)=(1,0)   (1-0, 2-2)=(1,0)
(3-1, 1-1)=(2,0)   (2-0, 2-2)=(2,0)
(3-1, 2-1)=(2,1)   (2-0, 3-2)=(2,1)
Island 1: (0,0),(1,0),(2,0),(2,1)
Island 2: (0,0),(1,0),(2,0),(2,1)  ✅ SAME!

Simple rule:
minX subtract → sabhi rows 0 se start
minY subtract → sabhi cols 0 se start
= shape ko top-left corner pe laao
= position ka effect remove ho jaata hai
= sirf SHAPE bachti hai ✅

Kyun dobara sort karte hain?
Pehla sort — minX, minY dhundne ke liye (agar sort na karo toh bhi chal jaata, loop se dhundh rahe hain)
Subtract ke baad order change ho jaata hai — isliye dobara sort zaroori hai.

Example:
Before subtract:
(-1, 2)
( 0, 0)
( 0, 1)

Pehla sort ke baad:
(-1, 2)  ← smallest
( 0, 0)
( 0, 1)

minX = -1, minY = 0
Subtract karo:
(-1-(-1), 2-0) = (0, 2)
( 0-(-1), 0-0) = (1, 0)
( 0-(-1), 1-0) = (1, 1)

Order ab:
(0, 2)   ← pehle wala bada ho gaya!
(1, 0)
(1, 1)
Dobara sort:
(1, 0)   ← sahi order
(1, 1)
(0, 2)

→

(0, 2)
(1, 0)
(1, 1)  ✅

Simple rule:
Subtract ke baad values change hoti hain
→ Pehla wala chota element ab chota nahi raha
→ Dobara sort karo taaki comparison sahi ho ✅

*/
