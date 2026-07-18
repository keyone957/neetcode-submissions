/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
      if(node==nullptr)
      {
        return node;
      }
      unordered_map<Node*, Node*> copied;
      //원본 노드 , 복사노드 
      //==> 이미 복사한 노드인지 확인하기 위해 사용

      Node* answer=new Node(node->val);//원본 노드 복사본 생성
     
      queue<pair<Node*,Node*>> q;
      //원본 노드, 복사노드
      q.push({node,answer});
      while(!q.empty())
      {
        Node* ori=q.front().first;
        Node* copy=q.front().second;
        q.pop();
        for(int i=0;i<ori->neighbors.size();i++)
        {
            Node* oriNeighbor=ori->neighbors[i];
            if (copied.find(oriNeighbor) == copied.end()) 
            //아직 복사하지 않은 노드면 
            // 새 복사 노드 생성
            {
                Node* copyNeighbor =new Node(oriNeighbor->val);
                copied[oriNeighbor] = copyNeighbor;
                q.push({oriNeighbor,copyNeighbor});
            }
            copy->neighbors.push_back(copied[oriNeighbor]);
        }
      }
return answer;

    }
};
