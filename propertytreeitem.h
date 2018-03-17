#ifndef PROPERTYTREEITEM_H
#define PROPERTYTREEITEM_H

#include <osg/Object>

#include <QList>
#include <QVariant>
#include <QStyleOptionViewItem>

enum PropertyTreeColumn
{
    ptcProperty,
    ptcValue,
    stcCount,
};

class PropertyTreeItem : public QObject
{
    Q_OBJECT
public:
    PropertyTreeItem(PropertyTreeItem *parent = nullptr);
    PropertyTreeItem(osg::Object* object);
    virtual ~PropertyTreeItem();

    PropertyTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;

    int row() const;
    PropertyTreeItem *parentItem();

    //tree model
    virtual Qt::ItemFlags flags(int column) const;
    virtual QVariant data(int column, int role) const;
    virtual bool setData(int column, const QVariant &value, int role);

    //tree delegate
    virtual bool createEditor(QWidget*& editor, QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    virtual bool setEditorData(QWidget* editor,const QModelIndex& index) const;
    virtual bool setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;
    virtual bool updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;
protected:
    PropertyTreeItem *m_ParentItem;
    QList<PropertyTreeItem*> m_ChildItems;
};

#endif // PROPERTYTREEITEM_H
