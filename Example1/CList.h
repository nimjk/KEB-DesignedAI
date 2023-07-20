#pragma once

template <typename T>
struct tListNode
{
    T data;
    tListNode<T> *pNext;
    tListNode<T> *pPrev;

    tListNode()
        : data(), pPrev(nullptr), pNext(nullptr)

    {
    }

    tListNode(const T &_data, tListNode<T> *_pPrev, tListNode<T> *_pNext)
        : data(_data), pPrev(_pPrev), pNext(_pNext)
    {
    }
};

template <typename T>
class CList
{
private:
    tListNode<T> *m_pHead;
    tListNode<T> *m_pTail;
    int m_iCount;
    // 내가 추가한 구문
public:
    CList() : m_pHead(nullptr), m_pTail(nullptr), m_iCount(0)
    {
    }

public:
    void push_back(const T &_data);
    void push_front(const T &_data);

public:
    ~CList();
};

template <typename T>
void CList<T>::push_back(const T &_data)
{
    // 입력된 데이터를 저장할 노드를 동적할당 함
    tListNode<T> *pNewNode = new tListNode<T>(_data, nullptr, nullptr);

    if (nullptr == m_pHead)
    {
        // 처음 입력된 데이터라면
        m_pHead = pNewNode;
        m_pTail = pNewNode;
    }
    else
    {
        // 데이터가 1개 이상에서 입력된 경우
        // 현재 가장 마지막 데이터(tail)를 저장하고 있는 노드가
        // 새로 생성된 노드와 서로 가리키게 한다.
        m_pTail->pNext = pNewNode;
        pNewNode->pPrev = m_pTail;

        // List가 마지막 노드의 주소값을 새로 입력된 노드로 갱신한다.
        m_pTail = pNewNode;
    }
    // 데이터 개수 증가
    ++m_iCount;
}

template <typename T>
void CList<T>::push_front(const T &_data)
{
    // 새로 생성된 노드의 다음을 현재 헤드노드의 주소값으로 채움
    tListNode<T> *pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

    // 현재 헤드노드의 이전노드 주소값을 새로 생성된 노드의 주소로 채움
    m_pHead->pPrev = pNewNode;

    // 리스트가 새로 생성된 노드를 새로운 헤드주소로 갱신한다.
    m_pHead = pNewNode;

    // 데이터 개수 증가
    ++m_iCount;
}
template <typename T>
CList<T>::~CList()
{
    tListNode<T>* pDeletNode = m_pHead;

    while (pDeletNode)
    {
        tListNode<T>* pNext = pDeletNode->pNext;
        delete (pDeletNode);
        pDeletNode = pNext;
    }
}
