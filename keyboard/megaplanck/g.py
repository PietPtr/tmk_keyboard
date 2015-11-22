l = ["Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M"]

for i in range(0, 12):
    print "        case GUI_" + str(i) + ":"
    print "            return (record->event.pressed ?"
    print "                MACRO( D(RGUI), D(" + l[i * 2] + "), W(255), U(RGUI), U(" + l[i * 2] + "), END ) :"
    print "                MACRO( D(RGUI), D(" + l[i * 2 + 1] + "), W(255), U(RGUI), U(" + l[i * 2 + 1] + "), END ));"

