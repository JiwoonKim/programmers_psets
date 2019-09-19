/**
 *  [5] 길찾기 게임
 *      - 이진트리를 구성하는 노드들의 좌표가 담긴 배열 nodeinfo가 매개변수로 주어질 때, 
 *        노드들로 구성된 이진트리를 전위 순회, 후위 순회한 결과를 2차원 배열에 순서대로 담아 반환하기
 *        (각 노드는 nodeInfo에 주어진 순서대로 번호를 가지며, nodeInfo에는 (x, y) 좌표가 기록되어있다)
 *      - Reference: https://programmers.co.kr/learn/courses/30/lessons/42891
 * 
 *      ** 효율성 테스트에 부분 점수가 있는 문제!!
 * 
 * 
 *  * Solution
 * 
 * 
 *  ** What I learned
 * 
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
vector<int> preorder_record;
vector<int> postorder_record;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    // 이진탐색트리 구성하기
    vector<pair<int, pair<int, int>>> nodes;
    for (int i = 0, n = nodeinfo.size(); i < n; i++) {
        pair<int, int> coord(nodeinfo[i][0], nodeinfo[i][1]);
        nodes.push_back(make_pair(i + 1, coord));
    }
    sort(nodes.begin(), nodes.end(), cmp);
    
    Node* head = new Node(nodes[0].first, nodes[0].second.first, nodes[0].second.second);
    queue<Node> q;
    q.push(*head);
    for (auto it = nodes.begin() + 1; it != nodes.end(); it++) {
        addNode(head, *it);
    }
    
    // 전위 순회 순서 기록하기
    preorder(head);

    // 후위 순회 순서 기록하기 
    postorder(head);

    // 전위 순회와 후위 순회 기록 담아 반환
    vector<vector<int>> answer = {preorder_record, postorder_record};
    return answer;
}

/**
 *  도움 함수: 각 노드를 루트에 가까운 순 (같은 깊이를 가진다면, 왼쪽 순) 정렬
 */
bool cmp(const pair<int, pair<int, int>>& u, const pair<int, pair<int, int>>& v) {
    auto u_coord = u.second;
    auto v_coord = v.second;
    if (u_coord.second == v_coord.second) {
        return u_coord.first < v_coord.second;
    }
    return u_coord.second > v_coord.second;
} 

/**
 *  노드 자료구조 정의
 */
class Node {
public:
    int number;
    int x, y;
    Node* left;
    Node* right;
    Node(int num, int x, int y) {
        this->number = num;
        this->x = x;
        this->y = y;
        this->left = nullptr;
        this->right = nullptr;
    }
};

/**
 *  도움 함수: 이진 탐색 트리를 구성하도록 노드를 삽입하기
 */
void addNode(Node* root, pair<int, pair<int, int>> node) {
    int number = node.first;
    auto coord = node.second;
    
    if (coord.first < root->x) {
        if (root->left) {
            addNode(root->left, node);
        } else {
            root->left = new Node(number, coord.first, coord.second);
        }
    }
    else {
        if (root->right) {
            addNode(root->right, node);
        } else {
            root->right = new Node(number, coord.first, coord.second);
        }
    }   
}

/**
 *  도움 함수: 전위 순회 기록
 */
void preorder(Node* head) {
    if (head) {
        preorder_record.push_back(head->number);
        preorder(head->left);
        preorder(head->right);
    }
}

/**
 *  도움 함수: 후위 순회 기록
 */
void postorder(Node* head) {
    if (head) {
        postorder(head->left);
        postorder(head->right);
        postorder_record.push_back(head->number);
    }
}