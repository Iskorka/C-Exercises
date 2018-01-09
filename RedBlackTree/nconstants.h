#ifndef NCONSTANTS_H
#define NCONSTANTS_H

namespace NConstants
{
    enum eColor
    {
        RED
        ,BLACK
    };


    template
    <typename T>
    struct sNode
    {
        sNode();

        ~sNode()
        {
//            if (m_parent->m_left == this)
//            {
//                m_parent->m_left = nullptr;
//            }
//            else
//            {
//                m_parent->m_right = nullptr;
//            }
        }

        eColor m_color;

        sNode* m_parent;
        sNode* m_left;
        sNode* m_right;

        T m_value;
    };

    template<typename T>
    sNode<T>::sNode() :
       m_color(RED)
      ,m_parent(nullptr)
      ,m_left(nullptr)
      ,m_right(nullptr)
    {}

}

#endif // NCONSTANTS_H
