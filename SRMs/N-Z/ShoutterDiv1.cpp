#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <utility>
#include <climits>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;

class ShoutterDiv1 {
 public:
  string vector_to_string(const vector<string>& v) {
    string s;
    for (int i=0;i<v.size();i++)
      s+=v[i];
    return s;
  }
  vector<int> getNumbers(const vector <string>& s1000, const vector <string>& s100, const vector <string>& s10, const vector <string>& s1) {
    string S1000 = vector_to_string(s1000);
    string S100 = vector_to_string(s100);
    string S10 = vector_to_string(s10);
    string S1 = vector_to_string(s1);
    vector<int> r;
    for (int i=0;i<S1000.size();i++) {
      string s = string(4,' ');
      s[0] = S1000[i];
      s[1] = S100[i];
      s[2] = S10[i];
      s[3] = S1[i];
      stringstream a(s);
      int c;
      a >> c;
      r.push_back(c);
    }
    return r;
  }
  int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1) {
    vector<int> s = getNumbers(s1000,s100,s10,s1);
    vector<int> t = getNumbers(t1000,t100,t10,t1);
    int n = s.size();
    int r = 0;
    vector<PII> intervals;
    int minl = 10000;
    for (int i=0;i<n;i++) {
      intervals.push_back(PII(s[i],t[i]));
      minl = min(minl,t[i]);
    }
    sort(intervals.begin(),intervals.end());
    for (int i=0;i<n;i++) {
      int right = minl;
      int idx = 0;
      while (idx < n) {
        if (intervals[i].first <= right) {
          right = max(right,intervals[i].second);
        }
        int maxl = right;
        bool done = true;
        while (idx < n && intervals[idx].first <= right) {
          done = false;
          maxl = max(maxl,intervals[idx].second);
          idx++;
        }
        if (done) return -1;
        if (idx == n) break;
        right = maxl;
        r++;
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"22", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"11", "1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"21", "4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"22", "2"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00", "0"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"11", "1"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"43", "6"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 2; verify_case(0, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { string Arr0[] = {"00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"00"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"13"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"00"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"00"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"24"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = -1; verify_case(1, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { string Arr0[] = {"0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1234"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"0000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"0000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"0000"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"2345"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 6; verify_case(2, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { string Arr0[] = {"0000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0000000000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"7626463146"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"0000000000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"0000000000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"0000000000"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"9927686479"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 18; verify_case(3, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { string Arr0[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"50353624751857130208544645495168271486083954769538"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"85748487990028258641117783760944852941545064635928"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"00000000000000000000000000000000000000000000000000"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"61465744851859252308555855596388482696094965779649"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"37620749792666153778227385275518278477865684777411"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 333; verify_case(4, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
void test_case_5() { string Arr0[] = {"56340314589885134294470346255852375301296041778903", "99649307249883423708705199508757826984524904448357", "58646446699266616769291068744630888441515832390586", "10494079934151273507373283091573698095022425030827", "27305866651716116503293678008811775174338956289709", "21868485909446961116242568775336643132317135058336", "67849891164612468430842084520399763043"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"46290906294890733416088393811878040940426643258706", "70150311807830448871162683271454369403023548074406", "69538965030553201957769547047314704701017939148984", "98252708374219461236140546411864826238330214572459", "38826212313082833948537424824759037853184315135991", "83014288631969551765629016446424853818538903712720", "55360148490036787387420917395059109655"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"75186176344744995159474587017953729940229708868813", "44987022454817752402432032087354373864998370454679", "69867169680244004339584259817400422086124170743813", "08327152137038878944659447014382791395327780654276", "06547470355477830576258432298406395558471972100421", "27030004759424728094038579479025142110494957981458", "41793528411633865185278774754019101406"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"64714253957818749418309214412136869471444345266732", "48633268203018614021625600772033219465013078898664", "69344211894881529820324997136769408709947624746952", "24303549152087929872926361556452298859535724935560", "09271176503799064161990693659825088239128730341230", "29650042312126283027646901032792191566439359197288", "82172250161528615334928034512100737328"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"56340314589995134294470356255852375401296041778903", "99649307249983423708705199508757827984524904448357", "59646446699266616869292068744630888441515832390686", "10494079934152273507373283091573698095022425030828", "27305866651716216603293678008812775174338956289709", "21868485909546961116243568775336643132317235058336", "67849891174612468430842184520399763043"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"57391907294001844427098404812978151140426844369817", "71261312808032549972263793281464370513134548174418", "70639976140663202058870658158414715712018949258084", "99363719374220661447251657522875846348340314583460", "49927223324092033059538435835760048964195415135991", "93014299742079663776621027557425963918549014832731", "55481248400146888497421018496159109666"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"04099790795004080823635699913195757068639045227302", "94583253692050775682750015529945543227970997286911", "33683539646114362486065220821102643838767426516086", "57413523759055199262336304235370822299758485866425", "26050710782997045567561644863820401088770576466944", "48595115446236310136230762374282456437732656409548", "65510389918715472158398596764219708502"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"54504600830449370709234453144628046679439040594239", "19021894871843095800688821629846852233012881005399", "54938316413041755814480489733080104253895347976753", "40666007065536276619851372750597178122200744394487", "32610189907399354633519138266785137015077157411889", "78167752685126572976794261888077129654694729159440", "99554963352263093194493466569182667926"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = -1; verify_case(5, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
void test_case_6() { string Arr0[] = {"76348910171080794280460083143694246161153804940976", "30720334610630692381702928579655724042294069473965", "03317522592047020994770918083522694152327802429081", "31902245218242841527898436509051887312257433448086", "15314526435810892690809728813888524246525142124867", "02671038520744526351696964388839136069812755942789", "64895319688692705370301656170148266146254254060712", "81179704080130460712874753706516686362481115836328", "99561670086452770469932982162836103445264937281248", "35953828743586621101325069909684622976325585725366", "74162442959893278713040880812290554454551240725711", "15588865513093131124054266663929846822770751001275", "51073358048877629407275907568599266282250595558900", "17965834694715615140035957914893725477356423086934", "62529210829349282081441763323877055485694740299782", "59880029518130277560997978432930066382654168361180", "21542373718330791874260213465313384886384276372315", "85630176845270723275959793778717012742022460371262", "42166622439497067105511174255969499976439131031033", "80900854031683961448730113734119159567283418730126", "86921959420206338283291419800343982154928916566351", "93898291056617420390660632713346138302009656215011", "21416974542351053731914412160584702242053144358814", "05490195014194832928320577053451548827240917978004", "12349566636199027977240357267128887236413749659485", "5301652"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"73800077039186322371856734744819273851889418592578", "84391126230982916729989289315048089529927910723094", "97988488020365810022441487545921551229737609906624", "07145739571631585214722140851237838574091160516680", "13386174987992977756931308277541605118318051562672", "00389488299954977736809243371573712282352150065751", "41962840981345159705290806577820797421724306172530", "63154019155250769799897476620596405787726988049078", "88748690646747928960555389102890408292302261007224", "11366309382619541200460146767655927516677741154847", "99013011047666197847597760740714296607029219801036", "72727659373154949065971619661661272679181237632271", "67998322035379150427557379704156722033463462740315", "45434934008393603472712906475025956263074993433736", "98420852045570781036113753606515733829010013540824", "02051235436334149973265073164748657131565577602874", "85453163135168343569130954062340729635386490967128", "34110735906528586242772927430183375337908426541481", "99651416735626501975734532443704604333214952599681", "51409455549518188490722723814911673580687250785043", "69287111757046927066551608755417162578808333292130", "25841522345423460323905146510053494856044475303603", "46279577516293296606103010538595219179662586118405", "75118678769375623350186299368167676488663257007673", "83913786011322633184874996701717323842774192286638", "6475512"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"99328143694103252587346048935758819863348823109827", "71390660499128221566357361172315126143353554366732", "39877890303728376935210446959918900246489731336481", "71465956777638409984348319709968291808992023096279", "60067284612641255307578871864379072370432813536728", "36880523776084053410085107774155852757286653308996", "12289186222712735574998491784175038456632582577625", "04656187103847506617540639115826067045766207095739", "00451138022761122794360646888749637284574409125193", "37723738849087260090067594443664538655781900464121", "26218317571229622079076530369819154176394640613254", "96470184920328635051602425270521690305542235005661", "40346468811224518742863138866520499892505016016170", "42725106301978210363364249928151236688854608400980", "41314263402662802562341382269131785351440971642364", "10004963528876103414449565729065285861269372282898", "92610604863320173686425059341380600897403736065421", "68006342146522984617230058423673340273771563584468", "98516627967339153380887324754184731609112593472342", "07384188115033817881760781150722943191102489084947", "29609004784834074393193686612380224811922798357390", "76216160838768966085369704110571887813268488960046", "55184775676648671302748656678420037135982207470230", "82276488234099346331430888364322778467909428246136", "88104508566464604153670007686794956918849839534792", "4963152"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"07280823490228175691488514812340858610282843881339", "10026618453871596190073477006616803450162732113710", "17500162118279553796576463730936393818345524685832", "11074305415435875816897788416496137339719902792172", "52562131853904373651084012229548032444598456588360", "03150493684590722547915655250040931191728845024980", "81249184142324174256182932501836610554984307140480", "64250689156996363527787168346948509851291966443321", "51727804278067391093910823446475870876848564330043", "25554157364467668588859586428142461493112906766328", "88434050062397779077490082598117203474793084281603", "61646177807414721492388355070309363735664839274360", "53042891669372211625821186567012612057616552455348", "72790934260259194277797531437318629230294909902616", "09918958420896481235026783312147458106402244296670", "13711578858711864123503639494360131772583870969452", "04157195457932983492428945368251400913032201869418", "82542398146454167966069925925949291219536927584322", "56924824182059540699117744872399800478052419739904", "53657797757683064664226673565428122991062496679943", "83143077729395792881935607754164587605324873925623", "54891337527602964362766642911252490259774162521562", "69097752397554877660619470098703973816583219528124", "20756472435802706798065032006607795105963516149870", "80583186019930283307966088982840506376909304206042", "9856186"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"86348910172081794290560183143695256261254805950987", "40730334610630792382803939579656725042394169573975", "04428533592047120994770929183622794153427803529081", "31902246218242851527898436609052988412267433549086", "15325536545920993791909729814888624247526142124867", "02682048521744526452796964398839236079812755942789", "64995419698692706470311656180248266146254254060712", "81189705080130461813984763706526686363582216837339", "99662680186452871569942993162946104455264947281248", "35963829743587621101325069919784723976435585725467", "75162442959893289714050980812390564454552240825711", "15688866523093232124164267763929856823780751001275", "51184358049878629408286918668599366282250595558900", "17965834695725615150035958914893725477366533086934", "63529310829449382081441863424877055586694740399782", "59880029518130277670997978442931077382664278361280", "31542373718330791885260323465313485886394286482316", "85630276946270733275969894778727013743123460371272", "53166622439497067205611174255969499976439241042033", "80901854032684961458830213834219259577384418740126", "87931959520207438293291419900343982265929916576351", "93998291056617420390660632713346148302009656215011", "21417984543361064732914412160694703253153145359814", "15491196025194832928330588054462549838240918979004", "12349666636199127987340367367229887336423759669586", "5311652"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = {"15932298582590572614058087986940404485291530824612", "38415378385984049950390403436040190539238231035435", "91432632050876231257474431097436072642058854418767", "17598960694985819546776284153740283099334593030993", "36710505407325280171356552771745017551320294864796", "35821919493987987060129547411685345705487362569862", "52165273923569562116302928508252898965728829287941", "97509320679484991094309619724608609891150392081322", "99141822057899151182808431426334750546435202217659", "53607530884862554323875398818085050968019995464160", "94047256287898310991748083952257347858572569334148", "93128780418456343475004810094776404993204489733683", "97201362370492394761601722139156247455867674975757", "77679955301436707603915931789359999288526413553847", "90831283479081294376246186011915885272134346044939", "54161637478569269013599494515940901463707009853297", "16793578478579574503331007066461223966518924009660", "78530057131739828663725220863326380652351537965611", "43772716849778733295056554986848824575636005822991", "55613868944860289940134143035423177904090491906595", "62508216279461159316761939075557385002921745527485", "26082525647858890866918568931294616979284596836903", "78490729830714530830128541679018434211184690130819", "15460890803487948562627232793611970521965581341884", "96936088425322068328284939243120868273925517407141", "9925957"}; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arr6[] = {"57249217896254047518475224079139013011226824875609", "59043157755560318302930805301692575226011283224922", "77053718797183606633876924614144168507187931365673", "65475436887722722641466821686779511271980944065756", "64450005503972257882210168780587541731429370459590", "46773402588345176431006735848993038913840291368595", "67691038933560054834430333966209686012945786394514", "63724922087439027032059607847340088725719697468837", "38357154580150501974178641113564332652306591795895", "72216754646626820638432005321469002454370411564380", "76544365791420351104319103386999110227115732033159", "09086663611541165022943361625752342440869924494745", "08217768821013501837137836917644253209856363561563", "09077504951260135416470545471438890758025399336582", "70663690903017937582153284957367936026869398082242", "16916482992928795255873295145576501523900397087578", "65055511880165485984366921560062189051793499817294", "10866911941947161816814184125216550725846785950519", "70326888533426179072912381882810238596370900736388", "25356925827267473075255315391321193242704647637537", "78390461411411126835225669378535118707566379819650", "79260397458145416137612319633062745544489061634187", "49440365304441890649995007911232147726492789780285", "75805120368902354909535902370528088773315718002160", "40904937131778655779088220485041702578456207760096", "0757682"}; vector <string> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); string Arr7[] = {"07779677122723589614932240863071659658020112100478", "17751702643038252342397120445614947433561502583454", "47433948632522732909368158277892889690272720710964", "43223995010483336903041446582623516308132692756768", "50926245576432576918489395689222972973602019472712", "35938857446709845943830194096441533343556845540044", "32100806366149744702917435204268287615890515999167", "41209036706174333168235566754272161867086513568358", "42646027122715619398754677708378218962642905979775", "55193668585608465317230283652593374833451962079427", "75952547189166739550146671785631810278279575345343", "63481370365150564644120748183559663592367545284478", "50962285460443121344613348754816213609832799245187", "69302967590661490796792093442791435652433200146673", "38087119414603670797908972559727434679547704198129", "06988041227710242412400009658836006801455649428734", "70652040001236751382033089683121558959506946647072", "48047135953159800390720609742175974910277198231343", "55029104887435087924564741134384339509858564540486", "10593907073007573723610894352950682376876687467889", "79955810982330441321969067502170417508296841862472", "72405044641607536418601209038568645485073064862148", "29127546244559117159297288010258055075526061877807", "96460006997809723124623454653790219156958565667001", "09470547057089506084364942174042785605502976441940", "7418620"}; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); int Arg8 = 29670; verify_case(6, Arg8, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }


// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ShoutterDiv1 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
