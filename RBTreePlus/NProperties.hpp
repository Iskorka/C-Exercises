#ifndef NPROPERTIES_H
#define NPROPERTIES_H

namespace NProperties
{
    enum eNodeColor
    {
        RED, BLACK
    };

    template
    <typename T>
    struct sNode
    {
        sNode(T value);
        ~sNode();

        bool isRed();
        bool isBlack();

        void makeRed();
        void makeBlack();

        T m_value;
        sNode* m_left;
        sNode* m_right;
        eNodeColor m_color;
    };

    template<typename T>
    sNode<T>::sNode(T value) :
                    m_value(value)
                   ,m_left(nullptr)
                   ,m_right(nullptr)
                   ,m_color(RED)
    {
    }

    template<typename T>
    sNode<T>::~sNode()
    {
    }

    template<typename T>
    inline bool sNode<T>::isRed()
    {
        return (nullptr != this) && (m_color == RED);
    }

    template<typename T>
    inline bool sNode<T>::isBlack()
    {
        return (nullptr != this) && (m_color == BLACK);
    }

    template<typename T>
    inline void sNode<T>::makeRed()
    {
        m_color = RED;
    }

    template<typename T>
    inline void sNode<T>::makeBlack()
    {
        m_color = BLACK;
    }

}

#endif // NPROPERTIES_H
