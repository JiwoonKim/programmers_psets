# programmers_psets :ocean:
solutions to programmers problem sets

### :unlock: 코딩테스트 고득점 Kit 
- [ ] 1. 해시 (높음; 4 문제)
- [ ] 2. 스택/큐 (보통 6 문제)
- [ ] 3. 힙 (보통; 4 문제)
- [ ] 4. 정렬 (높음; 3 문제)
- [ ] 5. 완전탐색 (높음; 4 문제)
- [ ] 6. 그리디 (낮음; 7 문제)
- [ ] 7. 동적계획법 (낮음; 7 문제)
- [ ] 8. 깊이/너비 우선 탐색 (높음; 4 문제)
- [ ] 9. 이분탐색 (낮음; 3문제)
- [ ] 10. 그래프 (낮음; 4문제)

### :chocolate_bar: 카카오 블라인드 코딩테스트 기출
- [ ] 카카오 블라인드 코딩테스트 1차 2019
- [ ] 카카오 블라인드 코딩테스트 1차 2018
- [ ] 카카오 블라인드 코딩테스트 1차 2017

## :wrench: Useful Mechanisms To Remember
> list of useful mechanisms (functions) to remember

### 1. 해시
1. use `unordered_multiset` to insert and erase duplicate keys (1-1. 완주하지 못한 선수)
    - use `iterator` to erase only one and not all duplicate keys
    - use `unordered_map` instead if need to count number of duplicates: (key, count)
        - bcuz duplicate keys are iterated separately in multiset
2. `sort and compare` to check if prefix (1-1. 완주하지 못한 선수 & 1-2. 전화번호 목록 :star:)
    - 
3. use `counting principle` to __count__ all the possible combinations (1-3. 위장 :dizzy:)
    - add `not-chosen-case` to each categories and multiply all categories
    - if there are certain instances not allowed, simpy calculate number of those and subtract from total counts
    - use `backtracking` instead, to actually create all the possible combination representations

### 2. 스택/큐
### 3. 힙

### 4. 정렬

### 5. 완전탐색

### 8. 깊이/너비 우선 탐색