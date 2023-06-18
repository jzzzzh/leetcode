#include <iostream>
#include <vector>
#include <string>
using namespace std;
// err
vector<string> trulyMostPopular(vector<string> &names, vector<string> &synonyms)
{
    vector<string> ans;
    vector<string> just_name;
    vector<int> precentage;
    vector<int> list;
    int nnum = 0;
    for (string name : names)
    {
        int n = name.find_first_of("(");
        just_name.push_back(name.substr(0, n));
        precentage.push_back(stoi(name.substr(n + 1, name.length() - n)));
        list.push_back(nnum++);
    }

    for (string synonym : synonyms)
    {
        int n = synonym.find_first_of(',');
        string name1 = synonym.substr(1, n - 1);
        string name2 = synonym.substr(n + 1, synonym.length() - n - 2);
        int tmp = 0;
        int num = 0;
        for (int i = 0; i < nnum; i++)
        {
            if (just_name[i] == name1 || just_name[i] == name2)
            {
                if (num == 0)
                {
                    tmp = list[i];
                    while (tmp != list[tmp])
                    {
                        tmp = list[tmp];
                    }
                    num++;
                }
                else
                {
                    list[i] = tmp;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < list.size(); i++)
    {
        if (precentage[i] > 0)
        {
            string tmp_name = just_name[i];
            int precent = precentage[i];
            for (int j = i + 1; j < list.size(); j++)
            {
                if (list[i] == list[j])
                {
                    precent += precentage[j];
                    precentage[j] = 0;
                    if (tmp_name > just_name[j])
                    {
                        tmp_name = just_name[j];
                    }
                }
            }
            ans.push_back(tmp_name + "(" + to_string(precent) + ")");
        }
    }
    return ans;
}
int main()
{
    vector<string> names = {"Fcclu(70)", "Ommjh(63)", "Dnsay(60)", "Qbmk(45)", "Unsb(26)", "Gauuk(75)", "Wzyyim(34)", "Bnea(55)", "Kri(71)", "Qnaakk(76)", "Gnplfi(68)", "Hfp(97)", "Qoi(70)", "Ijveol(46)", "Iidh(64)", "Qiy(26)", "Mcnef(59)", "Hvueqc(91)", "Obcbxb(54)", "Dhe(79)", "Jfq(26)", "Uwjsu(41)", "Wfmspz(39)", "Ebov(96)", "Ofl(72)", "Uvkdpn(71)", "Avcp(41)", "Msyr(9)", "Pgfpma(95)", "Vbp(89)", "Koaak(53)", "Qyqifg(85)", "Dwayf(97)", "Oltadg(95)", "Mwwvj(70)", "Uxf(74)", "Qvjp(6)", "Grqrg(81)", "Naf(3)", "Xjjol(62)", "Ibink(32)", "Qxabri(41)", "Ucqh(51)", "Mtz(72)", "Aeax(82)", "Kxutz(5)", "Qweye(15)", "Ard(82)", "Chycnm(4)", "Hcvcgc(97)", "Knpuq(61)", "Yeekgc(11)", "Ntfr(70)", "Lucf(62)", "Uhsg(23)", "Csh(39)", "Txixz(87)", "Kgabb(80)", "Weusps(79)", "Nuq(61)", "Drzsnw(87)", "Xxmsn(98)", "Onnev(77)", "Owh(64)", "Fpaf(46)", "Hvia(6)", "Kufa(95)", "Chhmx(66)", "Avmzs(39)", "Okwuq(96)", "Hrschk(30)", "Ffwni(67)", "Wpagta(25)", "Npilye(14)", "Axwtno(57)", "Qxkjt(31)", "Dwifi(51)", "Kasgmw(95)", "Vgxj(11)", "Nsgbth(26)", "Nzaz(51)", "Owk(87)", "Yjc(94)", "Hljt(21)", "Jvqg(47)", "Alrksy(69)", "Tlv(95)", "Acohsf(86)", "Qejo(60)", "Gbclj(20)", "Nekuam(17)", "Meutux(64)", "Tuvzkd(85)", "Fvkhz(98)", "Rngl(12)", "Gbkq(77)", "Uzgx(65)", "Ghc(15)", "Qsc(48)", "Siv(47)"};
    vector<string> synonyms = {"(Gnplfi,Qxabri)", "(Uzgx,Siv)", "(Bnea,Lucf)", "(Qnaakk,Msyr)", "(Grqrg,Gbclj)", "(Uhsg,Qejo)", "(Csh,Wpagta)", "(Xjjol,Lucf)", "(Qoi,Obcbxb)", "(Npilye,Vgxj)", "(Aeax,Ghc)", "(Txixz,Ffwni)", "(Qweye,Qsc)", "(Kri,Tuvzkd)", "(Ommjh,Vbp)", "(Pgfpma,Xxmsn)", "(Uhsg,Csh)", "(Qvjp,Kxutz)", "(Qxkjt,Tlv)", "(Wfmspz,Owk)", "(Dwayf,Chycnm)", "(Iidh,Qvjp)", "(Dnsay,Rngl)", "(Qweye,Tlv)", "(Wzyyim,Kxutz)", "(Hvueqc,Qejo)", "(Tlv,Ghc)", "(Hvia,Fvkhz)", "(Msyr,Owk)", "(Hrschk,Hljt)", "(Owh,Gbclj)", "(Dwifi,Uzgx)", "(Iidh,Fpaf)", "(Iidh,Meutux)", "(Txixz,Ghc)", "(Gbclj,Qsc)", "(Kgabb,Tuvzkd)", "(Uwjsu,Grqrg)", "(Vbp,Dwayf)", "(Xxmsn,Chhmx)", "(Uxf,Uzgx)"};
    vector<string> ans = trulyMostPopular(names, synonyms);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
