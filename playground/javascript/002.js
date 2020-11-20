let f = (a, b, c) => {
    console.log(a, b, c);
};

let arr = [1, 2];
f(...arr);

let args = [
    pagination.current,
    pageSize,
    filters.status ? filters.status.toString() : '',
    sorter.columnKey
];
this.updateMarkListData(...args);


this.updateMarkListData(
    pagination.current,
    pageSize,
    filters.status && filters.status.toString(),
    sorter.columnKey
);

undataMarkListData = (page, pageSize, status='', sort={sortValue:'', sortType=''})

this.updateMarkListData(pagination.current, pageSize, filters.status && filters.status.toString() 
