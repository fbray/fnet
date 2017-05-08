/**
 * Created by ychung on 12/17/2015.
 */
function HandleLiveChatEvent(name) {

    function ShallRemove(dep) {
        //TODO: check the department name and page url , return true to remove this department
        if (dep.Name == "LinkSprinter, LinkRunner, or OneTouch" && (location.href.indexOf('/linksolutions/support') != -1 || location.href.indexOf('/truviewlive') != -1))
            return true;
        if (dep.Name == "OptiView" && (location.href.indexOf('/linksolutions') != -1 || location.href.indexOf('/truviewlive') != -1))
            return true;
        if (dep.Name == "TruView or Clearsight" && (location.href.indexOf('/linksolutions') != -1 || location.href.indexOf('/truviewlive') != -1))
            return true;
        if (dep.Name == "TruView Live" && location.href.indexOf('/linksolutions'))
            return true;
        if (dep.Name == "AirMagnet Product" && (location.href.indexOf('/linksolutions') != -1 || location.href.indexOf('/truviewlive') != -1))
            return true;
        if (dep.Name == "Customer Care" && (location.href.indexOf('/linksolutions') != -1 || location.href.indexOf('/truviewlive') != -1))
            return true;
        return false;
    }

    if (name == "Initializing") {
        var deps = MyLiveChat.Departments;
        var online = false;
        for (var i = 0; i < deps.length;) {
            if (ShallRemove(deps[i])) {
                deps.splice(i, 1);
            }
            else {
                if (deps[i].Online) online = true;
                i++;
            }
        }
        if (MyLiveChat.HasReadyAgents && !online) {
            MyLiveChat.HasReadyAgents = false;
        }
    }
}
