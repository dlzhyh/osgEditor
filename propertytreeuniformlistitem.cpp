#include "propertytreeuniformlistitem.h"
#include "propertytreeuniformitem.h"

#include <QPushButton>

PropertyTreeUniformListItem::PropertyTreeUniformListItem(PropertyTreeItem *parent, osg::StateSet::UniformList& uniformList)
    : PropertyTreeItem(parent)
    , UniformList(uniformList)
{
    for(auto i = UniformList.begin();i != UniformList.end();++i)
    {
        m_ChildItems.push_back(new PropertyTreeUniformItem(this, i));
    }
}

PropertyTreeUniformListItem::~PropertyTreeUniformListItem()
{
}

Qt::ItemFlags PropertyTreeUniformListItem::flags(int column) const
{
    return (Qt::ItemFlags)((ptcValue == column) ? Qt::ItemIsEditable : 0) | PropertyTreeItem::flags(column);
}

QVariant PropertyTreeUniformListItem::data(int column, int role) const
{
    if(Qt::DisplayRole == role)
    {
        switch(column)
        {
        case ptcProperty:
            return QVariant("UniformList");
        case ptcValue:
            return QVariant("...");
        }
    }
    return PropertyTreeItem::data(column, role);
}

bool PropertyTreeUniformListItem::setData(int column, const QVariant &value, int role)
{
    (void)(column);
    (void)(value);
    (void)(role);
    return true;
}

bool PropertyTreeUniformListItem::createEditor(QWidget*& editor, QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    (void)(option);
    (void)(index);
    editor = new QPushButton(parent);
    dynamic_cast<QPushButton*>(editor)->setText(tr("Add"));
    connect(dynamic_cast<QPushButton*>(editor), &QPushButton::clicked, this, &PropertyTreeUniformListItem::buttonClicked);
    return true;
}

bool PropertyTreeUniformListItem::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    (void)(editor);
    (void)(index);
    return true;
}

bool PropertyTreeUniformListItem::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    (void)(editor);
    (void)(model);
    (void)(index);
    return true;
}

bool PropertyTreeUniformListItem::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    (void)(index);
    QRect rect = option.rect;
    if(rect.width() > editor->width())
    {
        rect.setLeft(rect.right() - editor->width());
    }
    editor->setGeometry(rect);
    return true;
}

void PropertyTreeUniformListItem::buttonClicked(bool checked)
{
    (void)(checked);
    //todo: Add a mode item.
}
