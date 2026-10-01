out : mainmenu.o add.o print.o remove.o save.o search.o read.o update.o issue_book.o print_issue.o returnb.o
	cc mainmenu.c add.h print.h remove.h save.h search.h read.h update.h issue_book.h print_issue.h returnb.h -o out

main.o:mainmenu.c
	cc -c mainmenu.c

add.o:add.h
	cc -c add.h

print.o:print.h
	cc -c print.h

remove.o:remove.h
	cc -c remove.h

save.o:save.h
	cc -c save.h

search.o:search.h
	cc -c search.h

read.o:read.h
	cc -c read.h

update.o:update.h
	cc -c update.h

issue_book.o:issue_book.h
	cc -c issue_book.h

print_issue.o:print_issue.h
	cc -c print_issue.h

returnb.o:returnb.h
	cc -c returnb.h

clean:
	rm -f out *.o