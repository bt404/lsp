#include <stdio.h>
#include <sys/epoll.h>
#include <sys/inotify.h>

int main(void)
{
    int fd,wd,epfd,ret;
    fd=inotify_init();
    if(fd==-1)
    {
        perror("inotify_init\n");
        return 1;
    }
    wd=inotify_add_watch(fd,"./hehe",IN_DELETE);
    if(wd==-1)
    {
        perror("inotify_add_watch\n");
        return 1;
    }
    
    epfd=epoll_create(5);
    if(epfd==-1)
    {
        perror("epoll_create\n");
        return 1;
    }
    struct epoll_event event;
    event.events=EPOLLIN;
    event.data.fd=fd;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&event);
    if(ret==-1)
    {
        perror("epoll_ctl\n");
        return 1;
    }
    struct epoll_event retevent;
    ret=epoll_wait(epfd,&retevent,1,-1);
    if(ret==-1)
    {
        perror("epoll_wait\n");
        return 1;
    }
    ssize_t len=0;
    char buf[200];
    len=read(fd,buf,200);
    struct inotify_event *ievent;
    ievent=(struct inotify_event*)buf;
    printf("wd=%d mask=%d cookie=%d len=%d dir=%s\n",ievent->wd,ievent->mask\
            ,ievent->cookie,ievent->len,(ievent->mask&IN_ISDIR)?"yes":"no");
    if(ievent->len)
    {
        printf("name=%s\n",ievent->name);
    }

    close(fd);
    close(epfd);
    return 0;
}
