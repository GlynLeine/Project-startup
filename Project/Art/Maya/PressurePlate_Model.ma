//Maya ASCII 2019 scene
//Name: PressurePlate_Model.ma
//Last modified: Wed, Feb 26, 2020 03:01:03 PM
//Codeset: 1252
requires maya "2019";
requires "mtoa" "3.2.2";
requires "mtoa" "3.2.2";
currentUnit -l meter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2019";
fileInfo "version" "2019";
fileInfo "cutIdentifier" "201907021615-48e59968a3";
fileInfo "osv" "Microsoft Windows 10 Technical Preview  (Build 18362)\n";
fileInfo "license" "student";
createNode transform -s -n "persp";
	rename -uid "76AFB1DE-4D64-D791-1E6E-E19AD16E3C23";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 2.2622648311383635 0.24430878993182983 -1.3166691917274862 ;
	setAttr ".r" -type "double3" -2.7383527295770875 840.19999999979939 0 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "17302AFA-46CE-FF62-7ED5-30A037CDEE80";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".ncp" 0.001;
	setAttr ".fcp" 100;
	setAttr ".fd" 0.05;
	setAttr ".coi" 2.6205218714865812;
	setAttr ".ow" 0.1;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" 0 11.911315202713013 3.814697265625e-05 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "432997A8-4599-A6D4-801E-64A36703D9C8";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0.082559256978737783 10.001000000000001 2.8676927620509058 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "F812329B-439F-BB31-1FDD-1192B473E0A5";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".ncp" 0.001;
	setAttr ".fcp" 100;
	setAttr ".fd" 0.05;
	setAttr ".coi" 10.001000000000001;
	setAttr ".ow" 9.564029049140057;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "A8C59C43-4415-5B93-A7BC-D89C86DB55A5";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 10.001000000000001 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "8D5EC7F1-497D-D0E0-5974-1E9815543697";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".ncp" 0.001;
	setAttr ".fcp" 100;
	setAttr ".fd" 0.05;
	setAttr ".coi" 10.001000000000001;
	setAttr ".ow" 6.0012290575513081;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "D976D68D-4333-9950-E26D-8DBC3E7995E8";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 10.001000000000001 0 0 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "2DF310C5-4936-0CFC-A054-A7B09240EE31";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".ncp" 0.001;
	setAttr ".fcp" 100;
	setAttr ".fd" 0.05;
	setAttr ".coi" 10.001000000000001;
	setAttr ".ow" 0.3;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "pCube1";
	rename -uid "414EA56B-43C7-6973-E9E9-3AB98E1733D2";
	setAttr ".t" -type "double3" 0 -0.0082253381797373487 0 ;
	setAttr ".rp" -type "double3" 0 0.1761645791246518 0 ;
	setAttr ".sp" -type "double3" 0 0.1761645791246518 0 ;
createNode mesh -n "pCubeShape1" -p "pCube1";
	rename -uid "F22B9C65-4619-7991-735A-30978D9D79C0";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.74063915014266968 0.42743298411369324 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode mesh -n "polySurfaceShape1" -p "pCube1";
	rename -uid "FCCDB8D1-4BE8-9866-2808-2497F4B40E4B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 1.3803626298904419 0.27551022171974182 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 38 ".uvst[0].uvsp[0:37]" -type "float2" 1.26225901 0.90174258
		 1.25981271 0.9018299 1.25053954 0.60825515 1.23039138 0.2842887 1.23082018 0.28669816
		 1.55684888 0.89140147 1.55440247 0.89148879 1.54518032 0.59825361 1.53228188 0.26422706
		 1.22924042 0.30319431 1.24958217 0.59002149 1.23177445 0.30044514 1.53085899 0.2782082
		 1.53374553 0.28065065 1.24937439 0.59242505 1.25081778 0.60636216 1.25197411 0.58951205
		 1.54235649 0.57965511 1.5452162 0.58235288 1.54474473 0.59639448 1.25312531 0.60571742
		 1.54242074 0.59591508 1.54273367 0.59834093 1.52986956 0.26447058 1.23167038 0.30288795
		 1.53129482 0.28061584 1.25181508 0.5919618 1.54271948 0.58207393 1.25298619 0.60816783
		 1.82516313 0.24445513 1.82609773 0.25827354 0.93556392 0.30663729 1.22844338 0.28679338
		 1.22937715 0.30068463 0.93649846 0.3204557 1.52996659 0.26202962 1.53322077 0.278117
		 1.54478645 0.57991236;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 24 ".vt[0:23]"  -0.86105478 0.12538397 0.86105543 -0.86105478 0.13553904 0.87121046
		 -0.87120992 0.13553904 0.86105543 0.87120992 0.13553904 0.86105543 0.86105478 0.13553904 0.87121046
		 0.86105478 0.12538397 0.86105543 -0.87120992 0.21678999 0.86105543 -0.86105478 0.21678999 0.87121046
		 -0.86105478 0.2269451 0.86105543 0.86105478 0.2269451 0.86105543 0.86105478 0.21678999 0.87121046
		 0.87120992 0.21678999 0.86105543 -0.87120992 0.21678999 -0.86105454 -0.86105478 0.2269451 -0.86105454
		 -0.86105478 0.21678999 -0.8712095 0.86105478 0.21678999 -0.8712095 0.86105478 0.2269451 -0.86105454
		 0.87120992 0.21678999 -0.86105454 -0.87120992 0.13553904 -0.86105454 -0.86105478 0.13553904 -0.8712095
		 -0.86105478 0.12538397 -0.86105454 0.86105478 0.12538397 -0.86105454 0.86105478 0.13553904 -0.8712095
		 0.87120992 0.13553904 -0.86105454;
	setAttr -s 48 ".ed[0:47]"  0 2 0 2 18 0 18 20 0 20 0 0 1 0 0 0 5 0 5 4 0
		 4 1 0 2 1 0 1 7 0 7 6 0 6 2 0 3 5 0 5 21 0 21 23 0 23 3 0 4 3 0 3 11 0 11 10 0 10 4 0
		 6 8 0 8 13 0 13 12 0 12 6 0 8 7 0 7 10 0 10 9 0 9 8 0 9 11 0 11 17 0 17 16 0 16 9 0
		 12 14 0 14 19 0 19 18 0 18 12 0 14 13 0 13 16 0 16 15 0 15 14 0 15 17 0 17 23 0 23 22 0
		 22 15 0 20 19 0 19 22 0 22 21 0 21 20 0;
	setAttr -s 26 -ch 96 ".fc[0:25]" -type "polyFaces" 
		f 4 0 1 2 3
		mu 0 4 0 1 2 28
		f 4 4 5 6 7
		mu 0 4 4 3 35 23
		f 4 8 9 10 11
		mu 0 4 32 4 11 33
		f 4 12 13 14 15
		mu 0 4 5 6 22 7
		f 4 16 17 18 19
		mu 0 4 23 8 36 12
		f 4 20 21 22 23
		mu 0 4 9 24 16 10
		f 4 24 25 26 27
		mu 0 4 24 11 12 25
		f 4 28 29 30 31
		mu 0 4 25 13 37 17
		f 4 32 33 34 35
		mu 0 4 14 26 20 15
		f 4 36 37 38 39
		mu 0 4 26 16 17 27
		f 4 40 41 42 43
		mu 0 4 27 18 19 21
		f 4 44 45 46 47
		mu 0 4 28 20 21 22
		f 4 -8 -20 -26 -10
		mu 0 4 4 23 12 11
		f 4 -28 -32 -38 -22
		mu 0 4 24 25 17 16
		f 4 -40 -44 -46 -34
		mu 0 4 26 27 21 20
		f 4 -48 -14 -6 -4
		mu 0 4 28 22 6 0
		f 4 -16 -42 -30 -18
		mu 0 4 8 29 30 36
		f 4 -2 -12 -24 -36
		mu 0 4 31 32 33 34
		f 3 -5 -9 -1
		mu 0 3 3 4 32
		f 3 -17 -7 -13
		mu 0 3 8 23 35
		f 3 -11 -25 -21
		mu 0 3 33 11 24
		f 3 -27 -19 -29
		mu 0 3 25 12 36
		f 3 -23 -37 -33
		mu 0 3 10 16 26
		f 3 -39 -31 -41
		mu 0 3 27 17 37
		f 3 -35 -45 -3
		mu 0 3 15 20 28
		f 3 -47 -43 -15
		mu 0 3 22 21 19;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube2";
	rename -uid "18478B6E-4273-3F4E-8C7C-288036C6BAFF";
	setAttr ".rp" -type "double3" 0 0.070784137124115229 0 ;
	setAttr ".sp" -type "double3" 0 0.070784137124115229 0 ;
createNode mesh -n "pCubeShape2" -p "pCube2";
	rename -uid "0F6ED606-4256-99EF-0864-3A8721680185";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.26025397730384725 0.49999988918045801 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode mesh -n "polySurfaceShape2" -p "pCube2";
	rename -uid "70161A79-4EB6-E256-FDFE-639B305A462D";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.32322372496128082 0.14952028542757034 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 32 ".uvst[0].uvsp[0:31]" -type "float2" 0.50481606 0.51325607
		 0.5101459 0.84503698 0.50415921 0.8512457 0.1628623 0.85834122 0.15647811 0.85238707
		 0.14318785 0.15868801 0.16106072 0.48583949 0.14444596 0.15149164 0.15019727 0.13513364
		 0.15206994 0.14921786 0.50332046 0.1415723 0.49359688 0.1327125 0.50334179 0.12020972
		 0.16054508 0.49636576 0.16510786 0.51100111 0.16948119 0.48420265 0.49865383 0.48528838
		 0.5086394 0.49732706 0.49792022 0.50838268 0.49401388 0.1186071 0.15175658 0.15778726
		 0.49469087 0.14125331 0.16880356 0.49258891 0.49967769 0.49399841 0.17123421 0.50614095
		 0.50131655 0.13430086 0.83563364 0.16901493 0.83357102 0.18306397 -0.1822654 0.22913535
		 -0.18554901 0.21532059 0.14120452 0.13764168 0.50713819 0.48640418;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 20 ".vt[0:19]"  -1.020853519 0.094588868 0.98515564 -0.9851554 0.094588868 1.020853996
		 -0.9851554 0.13028705 0.98515564 0.9851554 0.13028705 0.98515564 0.9851554 0.094588868 1.020853996
		 1.020853519 0.094588868 0.98515564 -1.020853519 0.094588868 -0.98515487 -0.9851554 0.13028705 -0.98515487
		 -0.9851554 0.094588868 -1.020853162 0.9851554 0.094588868 -1.020853162 0.9851554 0.13028705 -0.98515487
		 1.020853519 0.094588868 -0.98515487 -1.020853519 0.011281209 0.98515564 -0.9851554 0.011281209 1.020853996
		 1.020853519 0.011281209 0.98515564 0.9851554 0.011281209 1.020853996 -1.020853519 0.011281209 -0.98515487
		 -0.9851554 0.011281209 -1.020853162 1.020853519 0.011281209 -0.98515487 0.9851554 0.011281209 -1.020853162;
	setAttr -s 36 ".ed[0:35]"  13 15 0 13 12 0 14 15 0 16 12 0 17 19 0 17 16 0
		 18 14 0 19 18 0 0 2 0 2 7 0 7 6 0 6 0 0 1 0 0 0 12 0 13 1 0 2 1 0 1 4 0 4 3 0 3 2 0
		 3 5 0 5 11 0 11 10 0 10 3 0 5 4 0 4 15 0 14 5 0 6 8 0 8 17 0 16 6 0 8 7 0 7 10 0
		 10 9 0 9 8 0 9 11 0 11 18 0 19 9 0;
	setAttr -s 18 -ch 72 ".fc[0:17]" -type "polyFaces" 
		f 8 -6 4 7 6 2 -1 1 -4
		mu 0 8 14 24 18 0 1 2 3 4
		f 4 8 9 10 11
		mu 0 4 5 20 15 6
		f 4 12 13 -2 14
		mu 0 4 9 7 30 8
		f 4 15 16 17 18
		mu 0 4 20 9 11 21
		f 4 19 20 21 22
		mu 0 4 21 10 31 16
		f 4 23 24 -3 25
		mu 0 4 25 11 19 12
		f 4 26 27 5 28
		mu 0 4 13 22 24 14
		f 4 29 30 31 32
		mu 0 4 22 15 16 23
		f 4 33 34 -8 35
		mu 0 4 23 17 0 18
		f 4 -15 0 -25 -17
		mu 0 4 9 8 19 11
		f 4 -19 -23 -31 -10
		mu 0 4 20 21 16 15
		f 4 -33 -36 -5 -28
		mu 0 4 22 23 18 24
		f 4 -26 -7 -35 -21
		mu 0 4 25 12 26 27
		f 4 -29 3 -14 -12
		mu 0 4 28 29 30 7
		f 3 -13 -16 -9
		mu 0 3 7 9 20
		f 3 -18 -24 -20
		mu 0 3 21 11 25
		f 3 -11 -30 -27
		mu 0 3 6 15 22
		f 3 -32 -22 -34
		mu 0 3 23 16 31;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "502A06E3-47D7-070A-4FE8-D387ABBEC263";
	setAttr -s 4 ".lnk";
	setAttr -s 4 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "71A82AA0-4C02-BB9F-8B17-4EAFA62DE1A8";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "04E1AD9B-4B49-68F2-0551-12A3100AD23B";
createNode displayLayerManager -n "layerManager";
	rename -uid "93854458-4EA4-6431-17C2-BB8231C7608F";
createNode displayLayer -n "defaultLayer";
	rename -uid "C4283E4F-47B4-ABE9-06D1-A28DA7A0A03C";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "620DB800-4208-5F9E-FC48-1F9BFD87E378";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "E2037A4F-4CD7-0860-B7FF-F88C788C5C15";
	setAttr ".g" yes;
createNode nodeGraphEditorInfo -n "MayaNodeEditorSavedTabsInfo";
	rename -uid "A930237E-4F93-D086-9D8D-E5826DB06469";
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" -785.71425449280639 -44.047617297323995 ;
	setAttr ".tgi[0].vh" -type "double2" 755.95235091353356 45.238093440494914 ;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "083B7A3A-4801-D7A5-A325-41A977B87D1A";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $nodeEditorPanelVisible = stringArrayContains(\"nodeEditorPanel1\", `getPanel -vis`);\n\tint    $nodeEditorWorkspaceControlOpen = (`workspaceControl -exists nodeEditorPanel1Window` && `workspaceControl -q -visible nodeEditorPanel1Window`);\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\n\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n"
		+ "            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n"
		+ "            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n"
		+ "            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n"
		+ "            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n"
		+ "            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n"
		+ "            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n"
		+ "            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n"
		+ "            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n"
		+ "            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1300\n            -height 700\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -docTag \"isolOutln_fromSeln\" \n            -showShapes 1\n            -showAssignedMaterials 0\n            -showTimeEditor 0\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n"
		+ "            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 0\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 0\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            -renderFilterIndex 0\n            -selectionOrder \"chronological\" \n"
		+ "            -expandAttribute 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n"
		+ "            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n"
		+ "            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n"
		+ "                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 1\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n"
		+ "                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 1\n                -autoFitTime 0\n                -snapTime \"integer\" \n"
		+ "                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -showCurveNames 0\n                -showActiveCurveNames 0\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                -valueLinesToggle 1\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 1\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n"
		+ "                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n"
		+ "                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -autoFitTime 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"timeEditorPanel\" (localizedPanelLabel(\"Time Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -autoFitTime 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -autoFitTime 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n"
		+ "                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n\tif ($nodeEditorPanelVisible || $nodeEditorWorkspaceControlOpen) {\n"
		+ "\t\tif (\"\" == $panelName) {\n\t\t\tif ($useSceneConfig) {\n\t\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n"
		+ "                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\t}\n\t\t} else {\n\t\t\t$label = `panel -q -label $panelName`;\n\t\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n"
		+ "                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\tif (!$useSceneConfig) {\n\t\t\t\tpanel -e -l $label $panelName;\n\t\t\t}\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"shapePanel\" (localizedPanelLabel(\"Shape Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tshapePanel -edit -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"posePanel\" (localizedPanelLabel(\"Pose Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tposePanel -edit -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"profilerPanel\" (localizedPanelLabel(\"Profiler Tool\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"contentBrowserPanel\" (localizedPanelLabel(\"Content Browser\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1300\\n    -height 700\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1300\\n    -height 700\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "92D0954B-4D0B-694A-23C9-B39084D4E71C";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode lambert -n "lambert8";
	rename -uid "67FDA74D-49FF-0A50-39AD-1FA7AEB757D1";
createNode shadingEngine -n "scrappySG";
	rename -uid "C2B84822-464D-5877-2778-329C5BC26AC6";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo1";
	rename -uid "FFE25EB0-4631-5346-31AC-A4A18EBF5C21";
createNode lambert -n "lambert4";
	rename -uid "EE15E83B-4C81-55E9-F52F-82BEBC5612D9";
createNode shadingEngine -n "gigbitSG";
	rename -uid "8075F891-4544-A081-8095-16AED068D1E8";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo2";
	rename -uid "D3C761D6-4920-44F5-4FE5-8AB904C566C7";
createNode polyMapCut -n "polyMapCut1";
	rename -uid "36DDD64C-4AB8-A784-93E2-90A95F41D67D";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "e[7:8]" "e[16]";
createNode polyTweakUV -n "polyTweakUV1";
	rename -uid "AEBA41F7-45F6-77CF-C6A8-B8B5AC95742C";
	setAttr ".uopa" yes;
	setAttr -s 6 ".uvtk";
	setAttr ".uvtk[3]" -type "float2" 0.024847711 -0.045751426 ;
	setAttr ".uvtk[35]" -type "float2" 0.024847711 -0.045751426 ;
	setAttr ".uvtk[38]" -type "float2" 0.024847711 -0.045751426 ;
	setAttr ".uvtk[39]" -type "float2" 0.024847711 -0.045751426 ;
	setAttr ".uvtk[40]" -type "float2" 0.024847711 -0.045751426 ;
	setAttr ".uvtk[41]" -type "float2" 0.024847711 -0.045751426 ;
createNode polyMapSewMove -n "polyMapSewMove1";
	rename -uid "F7126435-4181-FCA3-8541-5E95CC448FE6";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[5]";
createNode polyTweakUV -n "polyTweakUV2";
	rename -uid "E1A43022-4095-B313-4989-D9840EC4CB2B";
	setAttr ".uopa" yes;
	setAttr -s 40 ".uvtk[0:39]" -type "float2" 0.0087314844 -0.0015830994
		 0.0067124367 -0.0014646053 0.00097036362 -0.0015808344 -0.0065302849 -0.0013713837
		 0.0068215132 -0.0072864294 0.0048027039 -0.0071679354 0.0010703802 -0.0073543191
		 -0.0037788153 -0.0070471466 -0.005001545 -0.00146842 0.000613451 -0.0015804768 -0.0051342249
		 -0.0015226305 -0.0051401854 -0.007417053 -0.0051655769 -0.0074567199 0.00066006184
		 -0.0015739799 0.00093364716 -0.0015882254 0.00060594082 -0.0016277432 0.00070333481
		 -0.0073180199 0.00075900555 -0.0073712468 0.0010335445 -0.007347703 0.00092339516
		 -0.0016339421 0.001021862 -0.0073027015 0.0010697842 -0.007306397 -0.0042695999 -0.0075533688
		 -0.0050051212 -0.0015162528 -0.0051687956 -0.0074088275 0.00065350533 -0.0016221404
		 0.00075101852 -0.0073227286 0.00097095966 -0.0016287565 -0.0032908916 0.03132993
		 -0.005102396 0.031350374 0.00034534931 0.049049556 -0.0069410801 -0.00073361397 -0.0046981573
		 -0.0011124909 0.0026947856 0.048703223 -0.0054816008 -0.0070656836 0.00071084499
		 -0.007365346 0.0031120777 -0.0070854425 0.0027438402 -0.0082770586 0.010742188 -0.0027395487
		 0.010550499 -0.0016307831;
createNode polyMapCut -n "polyMapCut2";
	rename -uid "482D2A01-48EC-1A89-84DD-FBB5CCA7E374";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[27]";
createNode polyMapSewMove -n "polyMapSewMove2";
	rename -uid "D8048BE9-4022-F800-338F-D7AAE0BB6EEF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[7]";
createNode polyMapSewMove -n "polyMapSewMove3";
	rename -uid "E6C35B12-495E-B8D3-C4C5-15AC7D7CDCAD";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[16]";
createNode polyMapSewMove -n "polyMapSewMove4";
	rename -uid "97EDC2A4-4875-60EE-E76F-1B9C144AB187";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[0]";
createNode polyTweakUV -n "polyTweakUV3";
	rename -uid "C69502B5-4F0D-17EF-005D-B5B25C9C59C3";
	setAttr ".uopa" yes;
	setAttr -s 38 ".uvtk[0:37]" -type "float2" 0.010041833 0.0030287504
		 0.0099064112 0.0028611422 -0.0043251514 0.010017574 0.012249708 0.0028909445 0.0038430691
		 0.00080698729 0.0038421154 0.00085043907 -0.0017626286 -0.0048745871 0.00097823143
		 0.0013526678 -0.017394781 0.010541677 -0.0049526691 0.0098221898 0.014335871 0.0028350353
		 -0.00071382523 0.0010914803 -0.017032862 -0.0038901865 -0.0048755407 0.009845674
		 -0.0043975115 0.0098466277 -0.0049767494 0.0097135305 -0.002833128 -0.0047064424
		 -0.0026791096 -0.0048524737 -0.0018846989 -0.0049080849 -0.0044291019 0.009742558
		 -0.00190413 -0.0048028827 -0.0017637014 -0.0048319101 0.0010111332 0.0009855032 0.014270902
		 0.0028335452 -0.017033577 -0.0037786663 -0.0048925877 0.0097325444 -0.0026957989
		 -0.0047365427 -0.0043478012 0.0097618699 -2.5629997e-05 -0.034752131 0.0016444921
		 -0.034659863 0.012727499 -0.005392611 0.014707327 0.0026808977 0.014323354 0.0027724504
		 0.012346625 -0.0052992702 -0.00036418438 0.00076168776 -0.0028222799 -0.0048170686
		 -0.00071156025 0.0010955334 -0.017409563 0.01043123;
createNode polyMapSewMove -n "polyMapSewMove5";
	rename -uid "79471E46-49D3-7C47-624C-DCBDDE23230C";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[32]";
createNode polyMapCut -n "polyMapCut3";
	rename -uid "F90C095D-4B6F-7B16-856F-47978EE407DC";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[22]";
createNode polyTweakUV -n "polyTweakUV4";
	rename -uid "147D5BC3-4F9D-AAE3-90FE-F5A2499F9394";
	setAttr ".uopa" yes;
	setAttr -s 38 ".uvtk[0:37]" -type "float2" -0.00023031235 0.0010964274
		 -0.00022315979 0.0011283755 -0.0053358078 -0.00051319599 -0.00019657612 0.001100421
		 0.00069534779 -0.00096619129 0.00069725513 -0.00093346834 -0.0020529032 0.0013093948
		 0.00072646141 -0.00096678734 0.015099168 -0.012169391 -0.0047804117 -0.00052672625
		 -8.9406967e-06 0.0010878444 0.00091159344 -0.00093966722 0.010027289 0.0090615749
		 -0.0054526329 -0.00084245205 -0.005313158 -0.0011229515 -0.001943469 0.0018669963
		 -0.0019888878 0.0017552972 -0.0020341873 0.0013865232 -0.0053373575 -0.0006120801
		 -0.0020412207 0.0014132857 -0.0020508766 0.0013423562 0.00072896481 -0.00093215704
		 2.3841858e-05 0.0010900497 0.010023952 0.0089630485 -0.0047700405 -0.0011156201 -0.0019835234
		 0.0017999411 -0.0053408146 -0.00054585934 0.00069069862 -0.004912436 0.00087690353
		 -0.0049141645 0.00045144558 0.0050352812 -0.00018799305 0.0011408329 -3.4570694e-06
		 0.0011128187 0.00063514709 0.0050051808 0.00091326237 -0.00096917152 -0.0019468069
		 0.0019406676 0.00094413757 -0.00094372034 0.015137911 -0.011861593 -0.0053608418
		 -0.0028486252;
createNode polyMapSewMove -n "polyMapSewMove6";
	rename -uid "3313A2BF-452B-6FEC-88B7-28B7975124A0";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[40]";
createNode polyMapCut -n "polyMapCut4";
	rename -uid "865C4CAA-4C18-DD42-37D6-C49D6B6FCF1A";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[30]";
createNode polyTweakUV -n "polyTweakUV5";
	rename -uid "4B643421-47A8-0275-1857-0C8C04992D9B";
	setAttr ".uopa" yes;
	setAttr -s 38 ".uvtk[0:37]" -type "float2" 0.00028240681 -1.9550323e-05
		 0.00027823448 -3.7312508e-05 0.0025017262 0.0020474195 0.00026416779 -2.2649765e-05
		 0.00035524368 6.7055225e-05 0.00035393238 4.8816204e-05 0.002528429 -0.0024062395
		 0.00033652782 6.9797039e-05 -0.0098338127 0.0061018765 0.0026780367 0.0024915934
		 0.00016081333 -1.7642975e-05 0.00023198128 5.7041645e-05 -0.010992885 -0.0043830276
		 0.0025231838 0.0021212697 0.002702117 0.002586782 0.0019990206 -0.0029265285 0.0017056465
		 -0.0044673681 0.002487421 -0.0027589202 0.0025280714 0.0021415353 0.0024672747 -0.0024877787
		 0.0025272369 -0.0024247169 0.00033557415 4.9293041e-05 0.0001424551 -1.8775463e-05
		 -0.010976195 -0.0041480958 0.0026782751 0.0025179386 0.0015134811 -0.0028057098 0.0025045872
		 0.0020657778 0.00037336349 0.0022780299 0.00026917458 0.0022798181 -0.00011456013
		 -0.0022235513 0.00025987625 -4.6610832e-05 0.00015699863 -3.0457973e-05 -0.00021725893
		 -0.0022059083 0.00023186207 7.2360039e-05 0.00021362305 5.954504e-05 -0.0098428726
		 0.0059977472 0.0027110577 0.0026912689 0.0016762018 -0.0023141503;
createNode polyMapSewMove -n "polyMapSewMove7";
	rename -uid "B91376DD-4ADC-0B19-CB89-32850DEBF6A4";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[17]";
createNode polyMapCut -n "polyMapCut5";
	rename -uid "6C05BEAA-4070-1ECD-ECCD-0E90E75F2310";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[17]";
createNode polyMapCut -n "polyMapCut6";
	rename -uid "5DB19C59-4D0B-D174-C17E-6AB81D5353CA";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[11]";
createNode polyMapSewMove -n "polyMapSewMove8";
	rename -uid "58C2356A-4462-3D68-0E17-CBADA157B595";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[15]";
createNode polyMapSewMove -n "polyMapSewMove9";
	rename -uid "D063FAD6-4EA6-ABA5-082B-4D928516148E";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[1]";
createNode polyTweakUV -n "polyTweakUV6";
	rename -uid "DD12CFA5-47B7-E311-58FD-2F91C06D1AB1";
	setAttr ".uopa" yes;
	setAttr -s 38 ".uvtk[0:37]" -type "float2" -0.71141028 -0.085169375
		 -0.71241963 -0.086801708 -0.68153071 -0.18181998 -0.71181339 -0.084395647 -0.61496949
		 -0.047955275 -0.61590153 -0.049651742 -0.57918584 -0.15090585 -0.64595866 -0.28912723
		 -0.67959243 -0.18890288 -0.71350223 -0.079690754 -0.61824048 -0.044242442 -0.54438406
		 -0.25543711 -0.68131107 -0.18403143 -0.67862421 -0.18939394 -0.57790041 -0.15616286
		 -0.57707071 -0.15588689 -0.57895905 -0.1503019 -0.68045747 -0.18385541 -0.5797264
		 -0.15066373 -0.57989746 -0.14980736 -0.61632639 -0.048885524 -0.71390545 -0.078914881
		 -0.54521382 -0.25571311 -0.67882341 -0.18854082 -0.57825094 -0.15536779 -0.6808362
		 -0.18306363 -0.57464617 -0.15059766 -0.71227884 -0.084736049 -0.71467322 -0.079729736
		 -0.68608409 -0.18090138 -0.61028653 -0.04486382 -0.61849326 -0.043404043 -0.64512879
		 -0.28885126 -0.67945391 -0.18966988 -0.57739574 -0.15519157 -0.61550164 -0.04886812
		 -0.61749083 -0.043594599 -0.71719015 -0.088689685;
createNode polyMapCut -n "polyMapCut7";
	rename -uid "7603BFAA-46F7-5367-0021-548C4CFD3027";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[18]";
createNode polyMapSewMove -n "polyMapSewMove10";
	rename -uid "CB483CD3-40E3-4A59-C4F7-F5BA6B6C0D34";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[0]";
createNode polyMapSewMove -n "polyMapSewMove11";
	rename -uid "9A9DDD29-4A54-DFD2-1349-D5A8AC579662";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[33]";
createNode polyMapCut -n "polyMapCut8";
	rename -uid "15D2920A-473A-0D9A-CD72-A29243451491";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[21]";
createNode polyTweakUV -n "polyTweakUV7";
	rename -uid "F268320B-4F5F-E22F-8E2C-50B6DD603DEB";
	setAttr ".uopa" yes;
	setAttr -s 32 ".uvtk[0:31]" -type "float2" 0.0010467768 0.00033086538
		 -7.2658062e-05 -0.00029408932 -0.00081008673 -0.00026535988 -0.0013385564 0.00075536966
		 -0.0021271706 0.0007724762 -0.0019713491 0.00086459517 0.0024340004 -0.00028261542
		 -0.00035049021 0.000864923 -0.00036530197 0.00074738264 -0.0022444725 -0.0016113073
		 -0.0013381839 -0.00024068356 -0.0015090108 -0.00040525198 0.0021274984 -0.00061416626
		 0.0018107742 -0.00052112341 0.0024454892 -0.00028389692 0.0025228858 0.00060227513
		 0.0018994212 -0.0062220097 0.00077372789 0.00083315372 -0.00020475686 0.00076717138
		 -0.002225548 -0.0010578781 0.0022125393 -0.00040346384 -3.5792589e-05 0.0006223321
		 0.0018734634 -0.00047105551 -0.0012921691 -0.00035434961 -0.00027698278 -0.0055602789
		 -5.9068203e-05 -0.0055081844 0.00041119754 0.0061092377 0.00018943846 0.0061414838
		 -0.00057454407 0.00089579821 -0.0012286901 -0.00024878979 -0.0019719452 0.00078064203
		 0.00024944544 0.003256768;
createNode polyMapCut -n "polyMapCut9";
	rename -uid "4D9742A5-4B4B-564C-11A4-99992BAED7F0";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[30]";
createNode polyMapSewMove -n "polyMapSewMove12";
	rename -uid "14BFEC17-4B2F-B324-20BE-83AA92E035D6";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[30]";
createNode polyMapCut -n "polyMapCut10";
	rename -uid "19CA431A-45A6-8A08-24FD-ABA2CD0C1BEF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[30]";
createNode polyMapCut -n "polyMapCut11";
	rename -uid "9C1FDF8F-4653-D305-B1FD-F4813E63D402";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[10]";
createNode polyMapSewMove -n "polyMapSewMove13";
	rename -uid "2BD84203-4D4A-FB8B-EB17-599B6272C2FD";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[26]";
createNode polyMapSewMove -n "polyMapSewMove14";
	rename -uid "D3999630-425A-371B-E3AA-7095EF749D57";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[18]";
createNode polyMapCut -n "polyMapCut12";
	rename -uid "10BEED61-4768-DCB1-006A-FEA5D9B8DF70";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "e[4:5]" "e[7]";
createNode polyMapSewMove -n "polyMapSewMove15";
	rename -uid "268138FE-44ED-40B0-2F33-30B170774AC6";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[30]";
createNode polyTweakUV -n "polyTweakUV8";
	rename -uid "490D6A37-4F75-618C-9FDE-74AB655B107A";
	setAttr ".uopa" yes;
	setAttr -s 34 ".uvtk[0:33]" -type "float2" 0.010770798 -0.016216397
		 -0.0029404163 0.0011493564 -0.0028792024 0.0011327267 0.0043438077 -6.377697e-05
		 0.0046025366 -6.6936016e-05 0.0043224841 -0.00066173077 0.00068701804 0.0097173452
		 0.0040567815 -0.00019806623 0.004064396 -7.5876713e-05 -0.0036142468 0.00092971325
		 -0.0030578971 0.0011148453 -0.0028912425 0.0012901425 -0.014760569 0.0070053935 -0.0013385266
		 0.0096377134 0.0050238967 -0.0090817213 0.0050078034 -0.0092680454 0.0091475248 -0.0097111464
		 0.0041178912 -0.00010460615 -0.0033892989 0.001123786 0.00066256523 0.0099679232
		 0.0062923431 -0.0092061758 -0.0018233806 0.010622621 -0.0031128526 0.0012313128 -0.004308641
		 0.0065662861 -0.0045316815 0.0065063238 0.0034228712 -0.0056234002 0.0036522895 -0.0056502819
		 0.0042888224 -0.00022357702 0.0057207942 -0.012221098 -0.0014607161 0.0084284544
		 -0.0048394799 -0.0048747063 -0.0057997704 -0.0032910109 -0.014992252 0.0056093335
		 -0.0044445097 0.0045052767;
createNode polyMapCut -n "polyMapCut13";
	rename -uid "2F9D2C85-4B11-8290-B46E-A29C019A60AC";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[13]";
createNode polyMapSewMove -n "polyMapSewMove16";
	rename -uid "3D570FAE-44E8-7E22-3D39-85AC3954D56E";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[3]";
createNode polyMapCut -n "polyMapCut14";
	rename -uid "8F7899C6-43AA-4D05-4F26-51AC1B619DBF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[25]";
createNode polyMapSewMove -n "polyMapSewMove17";
	rename -uid "A4CA0502-4450-6A32-C712-10A7833E8896";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[6]";
createNode polyMapSewMove -n "polyMapSewMove18";
	rename -uid "69D452B9-4050-FDCC-C461-5B9C0CD972B4";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[1]";
createNode polyMapSewMove -n "polyMapSewMove19";
	rename -uid "518F494C-4B2F-431A-2A8E-039693210D78";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[2]";
createNode polyTweakUV -n "polyTweakUV9";
	rename -uid "D92BC6FD-4861-9904-1F45-31A19DC7689E";
	setAttr ".uopa" yes;
	setAttr -s 32 ".uvtk[0:31]" -type "float2" 0.0021650791 4.2915344e-05
		 -0.0084468126 5.531311e-05 -0.0068901181 0.0024564266 0.0015785992 -0.0032762885
		 0.0019485056 -0.0055101514 -0.001045242 -0.0024670362 0.0017861873 0.0015836954 0.00054119527
		 -0.00064241886 -0.00035503507 -0.0028041005 -0.0032569766 0.001499176 -0.004278928
		 0.0019796491 -0.0044676363 0.0044398904 0.0017402172 0.0014690161 0.0018798709 8.2850456e-05
		 0.0019113421 -1.6927719e-05 0.002153635 0.00015068054 -0.0010121763 -0.0025703311
		 -0.0032900274 0.0016024113 0.0018409342 0.0015003681 0.0019810796 0.00011610985 0.0020022243
		 0.0015708208 -0.0041658282 -0.0006274581 0.0092275739 -0.0055580139 0.0092417002
		 -0.0035228133 -0.0045142174 0.0051432848 0.0019859076 1.513958e-05 0.0017087311 0.001568675
		 0.0086829066 -0.0054025054 -0.0045255572 0.0042506456 0.0019495338 0.0016684532 -0.0011600554
		 -0.0049116015 -0.006916523 0.006114006;
createNode polyMapCut -n "polyMapCut15";
	rename -uid "DD6AFBC6-40D2-7810-50E0-97ACFC6F9806";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[2]";
createNode polyMapCut -n "polyMapCut16";
	rename -uid "7C0D8CBE-4547-D630-D1C8-49BB3E000CA1";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[1]";
createNode polyTweakUV -n "polyTweakUV10";
	rename -uid "F20392AF-4DA0-D32C-9E5D-41B0012EF013";
	setAttr ".uopa" yes;
	setAttr -s 34 ".uvtk[0:33]" -type "float2" -0.01021713 -0.24710476 0.0081094503
		 -0.380941 0.0060071349 -0.37742317 -0.11554703 -0.38071951 -0.11993612 -0.37432271
		 -0.11631094 -0.37407899 -0.12787244 -0.26295388 -0.12114352 -0.38590115 -0.11363105
		 -0.37636977 0.0045498013 -0.36858618 0.0026786327 -0.37220746 -0.1023289 -0.50361949
		 -0.12524888 -0.26480252 -0.012460828 -0.25442004 -0.0095974207 -0.25408942 -0.013180017
		 -0.24685919 -0.11344911 -0.37374473 0.0016878843 -0.36892039 -0.12535509 -0.26192737
		 -0.013027728 -0.25159669 -0.1262635 -0.25725567 0.0053288937 -0.36842665 0.0010948181
		 -0.4842678 0.0058581829 -0.48590872 -0.1070593 -0.50469255 -0.010299921 -0.25198793
		 -0.12811229 -0.26513314 -0.00024485588 -0.4866398 -0.10005975 -0.50531918 -0.12916705
		 -0.25815749 -0.11578619 -0.3735981 0.012984574 -0.38254395 0.011859715 -0.37057859
		 -0.11637174 -0.38480517;
createNode animCurveTL -n "pCubeShape2_pnts_0__pntx";
	rename -uid "A3DFBC30-4CEC-3783-2752-80AB0333C900";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_0__pnty";
	rename -uid "65E2AB90-4E9C-A6EB-4C02-A8ACE3803342";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_0__pntz";
	rename -uid "4F2156CA-4F1A-0437-2A13-C7AF5C94E733";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_10__pntx";
	rename -uid "BE78AB54-4471-DCD4-2709-A6A72534ABA7";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_10__pnty";
	rename -uid "C91E1876-4667-A08B-1598-60BFB9C89CA3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_10__pntz";
	rename -uid "7EE42F05-49A5-48BD-8DDA-11914E5119DD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_11__pntx";
	rename -uid "6FF2001D-4764-D2B7-861E-B0A948962F92";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_11__pnty";
	rename -uid "6A2BA91C-476C-2785-BEA3-DEBBCB5B15FD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_11__pntz";
	rename -uid "4F3A683D-472E-FF40-35EB-66BDDF6A2A44";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_12__pntx";
	rename -uid "8974C6FA-4DCD-1057-D0D3-5B9DE8027537";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_12__pnty";
	rename -uid "EE01B5CE-48C3-140E-95C3-EE959CC1F640";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_12__pntz";
	rename -uid "56E7F483-4ABD-EAE0-D561-A5BB57E5628D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_13__pntx";
	rename -uid "74F78DCD-4656-0956-A033-D9AE41EDE849";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_13__pnty";
	rename -uid "79B5BE4C-459C-01C8-199F-1999E97AD2F8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_13__pntz";
	rename -uid "4779C93B-4450-FD8D-5FE2-BEB525BC5F1E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_14__pntx";
	rename -uid "B6472D67-44B0-70C4-8E31-0D932ED749E5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_14__pnty";
	rename -uid "381B51B6-4F07-A2D0-8C57-289311DC9088";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_14__pntz";
	rename -uid "AD9959AD-4DFA-D4F6-27E2-8FA17216F75C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_15__pntx";
	rename -uid "FF20D3DC-49BF-7FF7-B09E-C39D164BDBD1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_15__pnty";
	rename -uid "1CBDA12C-4F57-B762-7424-31927C533837";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_15__pntz";
	rename -uid "CA06CE89-4A9C-CDF1-41AE-FFA9C2D53CC4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_16__pntx";
	rename -uid "32913E02-4D52-1240-BD1C-EDBAB5BD23A6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_16__pnty";
	rename -uid "DD358029-47D6-9DEE-85D2-B18A172D8514";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_16__pntz";
	rename -uid "14689B92-45BF-6998-E241-B0A93A8498D4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_17__pntx";
	rename -uid "82DC573E-4831-5AE0-4D79-4393BBA59B5D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_17__pnty";
	rename -uid "B7F6D640-471D-2683-C597-5F8878564E42";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_17__pntz";
	rename -uid "3BFB1A2A-4B84-1F20-6257-EBB11CAE5461";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_18__pntx";
	rename -uid "5BABE06F-4766-A896-9582-CABD15731D6E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_18__pnty";
	rename -uid "FA93587E-4CAD-251D-9719-8D9020F2D73F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_18__pntz";
	rename -uid "1A935DC6-4608-BDDD-017D-2696BC534209";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_19__pntx";
	rename -uid "073872F3-410E-16D4-3384-BA8BC442B0B2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_19__pnty";
	rename -uid "C9DD1127-4F87-F6FC-E4BD-489B7987F742";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_19__pntz";
	rename -uid "58FA8466-4F7D-BDAC-3EC3-38A929704273";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_1__pntx";
	rename -uid "AD88772E-4558-452A-8283-1D9687FA0B6C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_1__pnty";
	rename -uid "B815BFC7-4BDF-061B-C178-9CAC8D14B22E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_1__pntz";
	rename -uid "88CEE2AD-4565-907B-4A00-8389DF362CD1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_2__pntx";
	rename -uid "075D526E-4FEE-490E-68F9-46BDCA4964B3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_2__pnty";
	rename -uid "F167C231-4FA6-9A97-0EE3-E194F0CD14BA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_2__pntz";
	rename -uid "944CEF80-4EEF-3924-29D9-7AB13701C224";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_3__pntx";
	rename -uid "9DAD0827-4BB4-21BD-5594-E4B20A635071";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_3__pnty";
	rename -uid "0AB57825-4FFE-A882-CD1F-98B21036B3AF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_3__pntz";
	rename -uid "E4F36193-4CBD-C135-CFBC-A785B5E021EF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_4__pntx";
	rename -uid "C3144B60-4795-97A8-6C3E-73918F956AEC";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_4__pnty";
	rename -uid "065462E3-47C7-4511-37E6-F2856B88D05F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_4__pntz";
	rename -uid "FBEF3525-4FFD-091A-5D38-A88A2E4F4C66";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_5__pntx";
	rename -uid "8581B05B-463A-65EE-010F-DB84B898BF6F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_5__pnty";
	rename -uid "3D05A654-4DD8-2D61-62D4-6697B9A6AC1C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_5__pntz";
	rename -uid "9C174E79-4426-6ECA-E784-8EAD54498FF8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_6__pntx";
	rename -uid "6A7CF01C-45CD-EE40-02BC-74818393EBFF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_6__pnty";
	rename -uid "39748182-4670-773E-07B9-6582832C0263";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_6__pntz";
	rename -uid "16EB36E1-4311-42F6-B25F-1896DD2162E8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_7__pntx";
	rename -uid "2F381C5C-4971-FE7F-007D-5087C64D29CC";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_7__pnty";
	rename -uid "9E0CDC7E-4BC7-4F82-09FE-11B88352908C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_7__pntz";
	rename -uid "8405706B-4F2A-6E99-AE63-4C82C2D5F4A0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_8__pntx";
	rename -uid "3037358C-453C-AAB1-D7E6-3A9930F3C197";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_8__pnty";
	rename -uid "3F3A4236-422D-F699-0279-71AC11D46402";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_8__pntz";
	rename -uid "5ABFA0E8-456A-8098-40D4-D7B89EF50F62";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_9__pntx";
	rename -uid "E857A6FE-4097-DC81-90D4-6BABD6548801";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_9__pnty";
	rename -uid "E70FB227-4208-C395-EE88-E0B74BD4F494";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "pCubeShape2_pnts_9__pntz";
	rename -uid "1A8A74D1-497C-86F3-2A01-349B2125F294";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube2_rotateX";
	rename -uid "C9CB9E55-4864-196E-E5E0-47879F371848";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube2_rotateY";
	rename -uid "D52DE66D-4260-EC98-94E9-269618FC209A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube2_rotateZ";
	rename -uid "561962EA-42C5-B45C-123A-37865E90D7F1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode polyMapSewMove -n "polyMapSewMove20";
	rename -uid "54B65C39-43DB-046E-5F3E-23820F8D0DDF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[8]";
createNode polyMapCut -n "polyMapCut17";
	rename -uid "4FB1F47C-475C-8549-AE45-37A4CA247960";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[0]";
createNode polyTweakUV -n "polyTweakUV11";
	rename -uid "A0902267-4DAC-ABF8-48AA-0DA6F95C0963";
	setAttr ".uopa" yes;
	setAttr -s 38 ".uvtk[0:37]" -type "float2" -0.0260005 0.0091959238 -0.02530247
		 0.01021415 -0.027828634 -0.006218195 -0.025084615 0.0092872977 -0.008818388 -0.0098547339
		 -0.008882463 -0.0097254515 -0.024720728 -0.010285199 -0.035063267 -0.013511579 -0.028420091
		 -0.0063760281 -0.024705052 0.0096821189 -0.0069040656 -0.0092618465 -0.028768897
		 -0.018545181 -0.027920127 -0.0060760379 -0.02845037 -0.0064561069 -0.024788141 -0.010710031
		 -0.024725914 -0.010754198 -0.024721622 -0.010249346 -0.027861416 -0.0061277747 -0.024788976
		 -0.010213315 -0.024784207 -0.010143638 -0.0085942745 -0.0096290112 -0.024512887 0.0097693205
		 -0.028830945 -0.018501021 -0.028357863 -0.006410718 -0.024793088 -0.010631979 -0.027778566
		 -0.0060740113 -0.024360538 -0.011067241 -0.024836063 0.0096191764 -0.028163791 -0.0070524216
		 -0.0084568262 -0.010604739 -0.0065943003 -0.0092215538 -0.035001278 -0.013555739
		 -0.028512597 -0.0064119697 -0.024739385 -0.010682315 -0.0085574389 -0.0099371076
		 -0.0067964792 -0.0095481873 -0.02653116 0.0079321861 -0.025803864 0.0072888732;
createNode polyMapSewMove -n "polyMapSewMove21";
	rename -uid "359908ED-4009-0A7F-E46D-CDAFEBC1AD36";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[8]";
createNode polyTweak -n "polyTweak1";
	rename -uid "1F3169ED-4482-2E72-A049-81AA0404F69C";
	setAttr ".uopa" yes;
	setAttr -s 20 ".tk";
	setAttr -s 20 ".tk";
createNode unitConversion -n "unitConversion1";
	rename -uid "002C1786-4713-444A-F446-D98640C2242E";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion2";
	rename -uid "1F404DF2-4332-1C37-1FFD-14B3967EC849";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion3";
	rename -uid "C114357F-406D-8AC2-507F-198D04F2ADE4";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion4";
	rename -uid "BDB25365-47D7-9FDB-2895-99B3E4E46292";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion5";
	rename -uid "8E13DAFA-49B3-A4ED-E044-3FB5463B248D";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion6";
	rename -uid "A8DFFCA3-406E-74B1-D155-3B8BCCE2D0DF";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion7";
	rename -uid "D56B9DED-473C-4AC8-EFCF-BDAB12EB7475";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion8";
	rename -uid "03E96882-4071-F87A-0A49-4B8D6093C899";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion9";
	rename -uid "D77F0874-4780-059D-A124-CA8B18950F0A";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion10";
	rename -uid "DF4B0A01-451F-5F02-0C73-87A7FF875008";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion11";
	rename -uid "967A5789-4D28-F06C-E6E4-EF80EF0AD4B3";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion12";
	rename -uid "7AD28255-4552-056B-3EA2-ADA438D1F0DF";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion13";
	rename -uid "39A0A680-4431-BFC7-0781-F084CB3B4F09";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion14";
	rename -uid "2BED4754-4788-196E-20CE-A6881692BCB3";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion15";
	rename -uid "D67CE500-48F0-5CC7-F365-2CB74FC4B560";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion16";
	rename -uid "A39705AF-4B6E-8910-112A-B898B6A7BDF5";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion17";
	rename -uid "3EF7D6BB-428A-5259-46E4-A1A27C43B1A3";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion18";
	rename -uid "94C46B0E-4B2E-AB8D-31AD-F88BC411F44C";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion19";
	rename -uid "7749581F-4815-FAB7-6AA1-BB9FBD64F6CE";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion20";
	rename -uid "83569723-40AE-9010-0738-7CB54417EE46";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion21";
	rename -uid "7D587902-4401-EA70-7547-DCA652E1601F";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion22";
	rename -uid "71D86FFB-4265-D2AF-6446-869BFF8B8A32";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion23";
	rename -uid "9C4C9E24-4932-9B13-0954-8EA2D36503CF";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion24";
	rename -uid "B20BCCAE-469B-EEE1-B57D-FB875D528617";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion25";
	rename -uid "9082A9F7-4CF6-B17E-37BA-D4A1C7573003";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion26";
	rename -uid "1319FEEA-4E8E-170D-8C32-07B696095AFE";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion27";
	rename -uid "4BC81256-4043-7123-0A75-8B9C9CF4640A";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion28";
	rename -uid "957E4C91-48EB-BE4A-55E6-4D92B0560268";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion29";
	rename -uid "4BCB7369-4D60-7E22-48B6-A6A4F9EAADAA";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion30";
	rename -uid "1CB92645-4759-29D7-DF2D-18A71BE914D1";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion31";
	rename -uid "629F7C90-4765-4C8A-1F8D-FA811FD2FFF2";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion32";
	rename -uid "66FE08EB-4933-7FAC-6220-A48EE785E18B";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion33";
	rename -uid "4F2ACD27-4C4E-3CCE-DFDB-C6BA9B22C457";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion34";
	rename -uid "43849549-4A83-1830-D0C3-889958562F6C";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion35";
	rename -uid "A5974D04-4CDA-2566-6D01-688D4EE38C08";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion36";
	rename -uid "CDE7C85E-4019-5F71-864C-EDA689D49344";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion37";
	rename -uid "67D6AEC4-45F1-7F75-7265-AEB435DDA033";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion38";
	rename -uid "7D188B9D-4D44-A1AC-8ED2-E990A8089DCC";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion39";
	rename -uid "579C7F50-4B09-D7D5-26FF-FEA231AA7159";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion40";
	rename -uid "700EAB86-46CD-6844-95D3-A0972A2A14C4";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion41";
	rename -uid "761A5431-48BF-8414-316D-D688C83E7B24";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion42";
	rename -uid "CEFB7415-4FBB-7CFA-1852-279C9370157D";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion43";
	rename -uid "182F3154-4A93-B0C4-E5D8-8998F2534D60";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion44";
	rename -uid "32658A4B-4228-EB4E-5D26-B481BA7DF7D0";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion45";
	rename -uid "E72B0B41-4A28-E007-5565-F48868B555B7";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion46";
	rename -uid "2FB37F67-4696-E06A-EA53-258E46FBFD20";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion47";
	rename -uid "FEE03498-4F69-B90B-E754-7C90D12F86B2";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion48";
	rename -uid "35BCB084-4BBE-45AD-5DF0-19AAF0FDD9C2";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion49";
	rename -uid "566CF2CE-4A24-70DC-E0FB-E3B04CA319B3";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion50";
	rename -uid "C434DB3D-447D-AA44-A573-14937DCEC2C4";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion51";
	rename -uid "AB6F2810-4A6E-75DB-EBAF-F2AEF2DCDA44";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion52";
	rename -uid "4A157F41-4A90-EB21-DC01-C1A40675A880";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion53";
	rename -uid "091A926C-4929-9B2E-8B31-56BCCB6AC1F4";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion54";
	rename -uid "D07350AB-4CFA-02A5-6A43-C8929A8A3577";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion55";
	rename -uid "23544FFB-4C96-9F0B-F6AE-468DDB6B12CF";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion56";
	rename -uid "49053455-48FB-5B76-CCC5-80A77EC21CB8";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion57";
	rename -uid "38B23B3E-4C55-D34E-9E1F-D1BE7B4C07AB";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion58";
	rename -uid "24452440-47CB-2CBF-63C8-98B1E85B1DA9";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion59";
	rename -uid "4CD268EA-4EDF-F6E9-D5CE-F5B8E477D596";
	setAttr ".cf" 0.01;
createNode unitConversion -n "unitConversion60";
	rename -uid "8E7EEF80-4AF2-C29B-508F-37B05DA70B6F";
	setAttr ".cf" 0.01;
createNode polyMapCut -n "polyMapCut18";
	rename -uid "F2C365DB-4B45-4FBC-1DA7-1B9CC944B9C8";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[12]";
createNode polyTweakUV -n "polyTweakUV12";
	rename -uid "69FB8C78-4759-F5E1-B66A-E58BEB04A767";
	setAttr ".uopa" yes;
	setAttr -s 34 ".uvtk[0:33]" -type "float2" -0.0066962242 0.0047981143
		 0.0061776042 -0.00036394596 0.0063710213 -0.00010746717 0.006588351 0.00067859888
		 0.0067423992 -0.0015188456 0.0069813132 0.0022471547 -0.0065773316 -0.0046539307
		 0.0063941721 0.0013946593 0.0054984353 0.00017523766 0.0070853829 0.0011379719 0.006821543
		 0.00050413609 -0.0043874085 0.0041006599 -0.0063465536 -0.0043786168 -0.0059199333
		 0.0044568181 -0.0059238672 0.0047712326 -0.0067563057 0.004478693 0.0076957531 -0.00018596649
		 0.0070902407 0.0008186698 -0.0066614151 -0.0043680072 -0.0062358379 0.0044363141
		 -0.0071820915 -0.0044214129 0.0068894029 0.00023728609 -0.0044800043 -0.0034834687
		 -0.0044810176 -0.0039310809 -0.0043863505 0.004548274 -0.0061624646 0.0047293305
		 -0.0063432977 -0.0053183436 -0.0046725571 -0.0033515925 -0.0045832656 0.0039694933
		 -0.0071159955 -0.0047472715 0.0061767101 -0.00082281232 0.0064236522 -0.00023931265
		 0.006393306 0.00093591213 0.0055826344 -0.0065265596;
createNode polyMapSewMove -n "polyMapSewMove22";
	rename -uid "5D656FBF-49FE-088D-5FFF-2D8618F24527";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[19]";
createNode polyMapCut -n "polyMapCut19";
	rename -uid "CD19522E-462B-867B-218B-D2B56D207C2D";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[23]";
createNode polyTweakUV -n "polyTweakUV13";
	rename -uid "143F45AD-46B0-10EA-F3FE-D9A5FA6D0D0A";
	setAttr ".uopa" yes;
	setAttr -s 34 ".uvtk[0:33]" -type "float2" 0.01163733 -0.009709239 -0.009493351
		 0.0048812032 -0.0098434091 0.0045089722 -0.0057314895 -0.0039783418 -0.0056846552
		 -0.0043376684 -0.0063987635 -0.0030650496 4.2617321e-06 0.010199547 -0.005455764
		 -0.005107522 -0.0062416978 -0.0034939349 -0.0093935728 -0.0031137466 -0.0093913376
		 0.0041000843 0.010779388 -0.0074588712 -0.00039814413 0.009757936 0.01040864 -0.0091776252
		 0.010407567 -0.010342479 0.011726022 -0.0091839433 -0.0063886978 -0.0031109452 -0.011888772
		 0.0037305355 0.00014789775 0.0097318888 0.010893941 -0.0091281533 0.0010178722 0.0098173618
		 0.009470582 0.0075421203 0.0094774365 0.0082808733 0.010772537 -0.0081976261 0.010780215
		 -0.0096093416 -0.00041977875 0.0099159479 0.0098126829 0.0072768247 0.011074807 -0.007201538
		 0.0009002164 0.010351658 -0.0094816089 0.0056302249 -0.010358691 0.0026076734 -0.0054440312
		 -0.00435853 -0.0063001476 -0.0040543377 -0.010997415 0.006295979;
createNode polyMapSewMove -n "polyMapSewMove23";
	rename -uid "FD9F160B-41C9-4180-0AC8-A292743DEEE9";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[21]";
createNode polyMapCut -n "polyMapCut20";
	rename -uid "25A302AC-4D92-B822-9154-0FBD79A5E086";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[33]";
createNode polyMapSewMove -n "polyMapSewMove24";
	rename -uid "72F0DCD7-4A5F-EBD1-090A-EBB5ACB2BFA1";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[10]";
createNode polyMapCut -n "polyMapCut21";
	rename -uid "B8551239-4941-63A8-D05D-79BEB9A008A0";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[26]";
createNode polyTweakUV -n "polyTweakUV14";
	rename -uid "00DDB6C6-4B08-1745-43C3-86A5632FD09E";
	setAttr ".uopa" yes;
	setAttr -s 34 ".uvtk[0:33]" -type "float2" -0.022103101 0.020339668
		 -0.010996073 -0.0012226105 -0.011076808 -0.0010363758 -0.024640843 0.0030426979 -0.024921656
		 0.0031241477 -0.025114927 0.004347086 -0.021798629 0.011453629 -0.025164805 0.0030172467
		 -0.024834253 0.0035052896 -0.010528594 -0.0008148849 -0.010685593 -0.0007764101 -0.025557913
		 -0.0061753727 -0.019170567 0.0039723516 -0.022035509 0.016933441 -0.021083415 0.014398754
		 -0.02221629 0.0176875 -0.024810016 0.0037721992 -0.010647446 -0.00064998865 -0.021618906
		 0.0040895939 -0.020125329 0.017162561 -0.020703737 0.0044537187 -0.014923394 -0.0092166588
		 -0.014559269 -0.009316558 -0.025921997 -0.0060754735 -0.015152276 -0.0093181115 -0.025413826
		 -0.0063835555 -0.02046469 0.0063728094 -0.010637641 -0.0013205111 -0.01079601 -0.0011177659
		 -0.024806362 0.0029193163 -0.024991281 0.0035437942 -0.010312319 -1.8656254e-05 -0.019861996
		 0.024924159 -0.020365957 0.0012067556;
createNode polyLayoutUV -n "polyLayoutUV1";
	rename -uid "488D72C4-47DF-F351-FDC7-DFB232221847";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:25]";
	setAttr ".l" 1;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
	setAttr ".rbf" 1;
	setAttr ".lm" 1;
createNode polyLayoutUV -n "polyLayoutUV2";
	rename -uid "9427F7B5-4061-69B2-45AB-35834E32968B";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:17]";
	setAttr ".l" 1;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
	setAttr ".rbf" 1;
	setAttr ".lm" 1;
createNode polyTweakUV -n "polyTweakUV15";
	rename -uid "1D291D89-40FB-0509-073B-538785218599";
	setAttr ".uopa" yes;
	setAttr -s 38 ".uvtk[0:37]" -type "float2" -0.00025165081 -0.94008279
		 -0.00039541721 -0.94685942 0.47581249 -0.48001742 -0.0045813322 -0.94350976 -0.46809137
		 -0.46392167 -0.46422184 -0.46785954 0.0040934682 6.92904e-05 0.9781217 0.013536589
		 0.50191331 -0.45330593 -0.026878476 -0.96536589 -0.49000514 -0.49398121 0.50639117
		 0.49360886 0.47880197 -0.47616598 0.50205696 -0.44652942 0.038076282 0.02568084 0.034206808
		 0.029618651 0.0081065297 0.0029078424 0.47543061 -0.47181177 0.012292445 -0.00044164062
		 0.0079630017 -0.0038685799 -0.46770942 -0.47212702 -0.030366302 -0.9696337 0.5102607
		 0.48967102 0.49772745 -0.44995642 0.034588754 0.021413058 0.47194302 -0.47607955
		 -0.017798305 0.022347808 -0.023507237 -0.96972007 0.49770433 -0.50229573 -0.4899832
		 -0.4416433 -0.49433458 -0.497408 0.9742521 0.017474497 0.50592649 -0.45046723 0.031217277
		 0.025767356 -0.47108066 -0.46777284 -0.49419105 -0.4906317 0.025509775 -0.966299
		 0.0036179423 -0.94402057;
createNode polyTweakUV -n "polyTweakUV16";
	rename -uid "33528141-4877-3DCD-D3A4-8DAB3A32DBF7";
	setAttr ".uopa" yes;
	setAttr -s 34 ".uvtk[0:33]" -type "float2" -0.49341488 -0.506585 0.032853246
		 0.022523761 0.033092976 0.0059444308 0.49769932 -0.44724438 0.50960249 -0.45883051
		 0.47876966 -0.48793736 0.014151156 -0.96483368 0.53393054 -0.46606964 0.47862566
		 -0.46699807 0.002107501 -0.0020444095 0.014008343 -0.013582408 0.96550089 0.018136244
		 0.012459755 -0.94030625 -0.44965768 -0.48790801 -0.46257484 -0.47762606 -0.48151278
		 -0.5181483 0.4658525 -0.47765568 0.0037947893 -0.026485682 0.0022491217 -0.95327294
		 -0.46243393 -0.49850205 -0.016830325 -0.97290713 0.48412365 0.48641905 0.46448332
		 0.5054993 0.98514116 -0.00094396574 0.50071591 0.48664722 0.96525991 0.034740198
		 -0.0049282312 -0.98447049 0.013213038 0.041601717 0.021189749 0.017530382 0.51429033
		 -0.44699159 0.49052656 -0.4785361 -0.0067216158 -0.013651937 -0.47433591 -0.48694134
		 0.022975922 -0.95314008;
createNode polyLayoutUV -n "polyLayoutUV3";
	rename -uid "5A7FB1B3-4168-1978-EAC5-25B3395681AF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:25]";
	setAttr ".l" 1;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
	setAttr ".rbf" 1;
	setAttr ".lm" 1;
createNode polyLayoutUV -n "polyLayoutUV4";
	rename -uid "828D800E-475A-323F-C575-50A2679FDA30";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:17]";
	setAttr ".l" 1;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
	setAttr ".rbf" 1;
	setAttr ".lm" 1;
createNode polyTweakUV -n "polyTweakUV17";
	rename -uid "CD53E7C7-4F03-D2E2-78F4-E793D88AA8CA";
	setAttr ".uopa" yes;
	setAttr -s 38 ".uvtk[0:37]" -type "float2" 0.51222533 -0.14080429 0.51270664
		 -0.14130646 0.51338631 -0.072872162 0.51215982 -0.14136714 0.44372201 -0.14020044
		 0.44428858 -0.14020538 0.4443166 -0.07226494 0.51402164 -0.0006053301 0.51334196
		 -0.069039702 0.51212782 -0.14457124 0.44431314 -0.14397198 0.44495216 0 0.51332372
		 -0.072375715 0.51286066 -0.068537533 0.44492409 -0.067940354 0.44435754 -0.067935377
		 0.44440183 -0.071767718 0.51276314 -0.072304398 0.44494864 -0.07170704 0.4448832
		 -0.072269887 0.44434515 -0.14076817 0.51218444 -0.14513403 0.4455187 -4.9481787e-06
		 0.51279515 -0.06910041 0.44498071 -0.068503112 0.51281971 -0.072867185 0.44111133
		 -0.072236866 0.51268846 -0.14464253 0.51659161 -0.072900206 0.44051671 -0.14017236
		 0.44424763 -0.14453483 0.51345509 -0.00060037337 0.5134272 -0.06854248 0.44442007
		 -0.068431795 0.44378453 -0.14069676 0.4437663 -0.14403266 0.51599717 -0.14083725
		 0.51279187 -0.14080924;
createNode polyTweakUV -n "polyTweakUV18";
	rename -uid "B7096883-4454-E3D9-B8A5-C887D2AE843A";
	setAttr ".uopa" yes;
	setAttr -s 34 ".uvtk[0:33]" -type "float2" 0.0023574531 -0.0094504356
		 -0.0035258234 -0.0022270083 -0.0033197403 -0.0022456646 0.0029124022 0.0029321313
		 0.0030717403 0.0030647814 0.0033929348 0.0026441216 0.008708328 -0.0037459731 0.0031933486
		 0.0033574104 0.0031327754 0.002669543 -0.0032609403 -0.0026407838 -0.0031021535 -0.0025080442
		 -0.0022559464 0.0093466043 0.0084016621 -0.0037350655 0.0021826327 -0.0088828802
		 0.0020380616 -0.0090298057 0.0025165081 -0.0093177557 0.0032484531 0.0024970174 -0.0029552281
		 -0.0026516318 0.0085493028 -0.003878653 0.0022974312 -0.0090552568 0.0087682009 -0.0041411519
		 -0.0086972713 0.0039803684 -0.0089597702 0.0037613809 -0.0019934326 0.009565562 -0.0086784661
		 0.0041866302 -0.002462402 0.0093652606 0.0089273155 -0.0040085316 -0.0037882328 -0.0024460554
		 -0.0034790337 -0.0023783445 0.0029308647 0.003138423 0.0032915324 0.002802223 -0.0031282902
		 -0.0027654767 0.0021384656 -0.0091879368 0.0085746646 -0.0036213398;
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
	setAttr ".fprt" yes;
select -ne :renderPartition;
	setAttr -s 4 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 6 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderingList1;
select -ne :initialShadingGroup;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultRenderGlobals;
	setAttr ".ren" -type "string" "arnold";
select -ne :defaultResolution;
	setAttr ".pa" 1;
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :ikSystem;
	setAttr -s 4 ".sol";
connectAttr "polyTweakUV17.out" "pCubeShape1.i";
connectAttr "polyTweakUV17.uvtk[0]" "pCubeShape1.uvst[0].uvtw";
connectAttr "pCube2_rotateX.o" "pCube2.rx";
connectAttr "pCube2_rotateY.o" "pCube2.ry";
connectAttr "pCube2_rotateZ.o" "pCube2.rz";
connectAttr "polyTweakUV18.out" "pCubeShape2.i";
connectAttr "polyTweakUV18.uvtk[0]" "pCubeShape2.uvst[0].uvtw";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "scrappySG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "gigbitSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "scrappySG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "gigbitSG.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "lambert8.oc" "scrappySG.ss";
connectAttr "scrappySG.msg" "materialInfo1.sg";
connectAttr "lambert8.msg" "materialInfo1.m";
connectAttr "lambert4.oc" "gigbitSG.ss";
connectAttr "gigbitSG.msg" "materialInfo2.sg";
connectAttr "lambert4.msg" "materialInfo2.m";
connectAttr "polySurfaceShape1.o" "polyMapCut1.ip";
connectAttr "polyMapCut1.out" "polyTweakUV1.ip";
connectAttr "polyTweakUV1.out" "polyMapSewMove1.ip";
connectAttr "polyMapSewMove1.out" "polyTweakUV2.ip";
connectAttr "polyTweakUV2.out" "polyMapCut2.ip";
connectAttr "polyMapCut2.out" "polyMapSewMove2.ip";
connectAttr "polyMapSewMove2.out" "polyMapSewMove3.ip";
connectAttr "polyMapSewMove3.out" "polyMapSewMove4.ip";
connectAttr "polyMapSewMove4.out" "polyTweakUV3.ip";
connectAttr "polyTweakUV3.out" "polyMapSewMove5.ip";
connectAttr "polyMapSewMove5.out" "polyMapCut3.ip";
connectAttr "polyMapCut3.out" "polyTweakUV4.ip";
connectAttr "polyTweakUV4.out" "polyMapSewMove6.ip";
connectAttr "polyMapSewMove6.out" "polyMapCut4.ip";
connectAttr "polyMapCut4.out" "polyTweakUV5.ip";
connectAttr "polyTweakUV5.out" "polyMapSewMove7.ip";
connectAttr "polyMapSewMove7.out" "polyMapCut5.ip";
connectAttr "polyMapCut5.out" "polyMapCut6.ip";
connectAttr "polyMapCut6.out" "polyMapSewMove8.ip";
connectAttr "polyMapSewMove8.out" "polyMapSewMove9.ip";
connectAttr "polyMapSewMove9.out" "polyTweakUV6.ip";
connectAttr "polySurfaceShape2.o" "polyMapCut7.ip";
connectAttr "polyMapCut7.out" "polyMapSewMove10.ip";
connectAttr "polyMapSewMove10.out" "polyMapSewMove11.ip";
connectAttr "polyMapSewMove11.out" "polyMapCut8.ip";
connectAttr "polyMapCut8.out" "polyTweakUV7.ip";
connectAttr "polyTweakUV7.out" "polyMapCut9.ip";
connectAttr "polyMapCut9.out" "polyMapSewMove12.ip";
connectAttr "polyMapSewMove12.out" "polyMapCut10.ip";
connectAttr "polyMapCut10.out" "polyMapCut11.ip";
connectAttr "polyMapCut11.out" "polyMapSewMove13.ip";
connectAttr "polyMapSewMove13.out" "polyMapSewMove14.ip";
connectAttr "polyMapSewMove14.out" "polyMapCut12.ip";
connectAttr "polyMapCut12.out" "polyMapSewMove15.ip";
connectAttr "polyMapSewMove15.out" "polyTweakUV8.ip";
connectAttr "polyTweakUV8.out" "polyMapCut13.ip";
connectAttr "polyMapCut13.out" "polyMapSewMove16.ip";
connectAttr "polyMapSewMove16.out" "polyMapCut14.ip";
connectAttr "polyMapCut14.out" "polyMapSewMove17.ip";
connectAttr "polyMapSewMove17.out" "polyMapSewMove18.ip";
connectAttr "polyMapSewMove18.out" "polyMapSewMove19.ip";
connectAttr "polyMapSewMove19.out" "polyTweakUV9.ip";
connectAttr "polyTweakUV9.out" "polyMapCut15.ip";
connectAttr "polyMapCut15.out" "polyMapCut16.ip";
connectAttr "polyMapCut16.out" "polyTweakUV10.ip";
connectAttr "polyTweakUV6.out" "polyMapSewMove20.ip";
connectAttr "polyMapSewMove20.out" "polyMapCut17.ip";
connectAttr "polyMapCut17.out" "polyTweakUV11.ip";
connectAttr "polyTweak1.out" "polyMapSewMove21.ip";
connectAttr "polyTweakUV10.out" "polyTweak1.ip";
connectAttr "unitConversion1.o" "polyTweak1.tk[0].tx";
connectAttr "unitConversion2.o" "polyTweak1.tk[0].ty";
connectAttr "unitConversion3.o" "polyTweak1.tk[0].tz";
connectAttr "unitConversion4.o" "polyTweak1.tk[1].tx";
connectAttr "unitConversion5.o" "polyTweak1.tk[1].ty";
connectAttr "unitConversion6.o" "polyTweak1.tk[1].tz";
connectAttr "unitConversion7.o" "polyTweak1.tk[2].tx";
connectAttr "unitConversion8.o" "polyTweak1.tk[2].ty";
connectAttr "unitConversion9.o" "polyTweak1.tk[2].tz";
connectAttr "unitConversion10.o" "polyTweak1.tk[3].tx";
connectAttr "unitConversion11.o" "polyTweak1.tk[3].ty";
connectAttr "unitConversion12.o" "polyTweak1.tk[3].tz";
connectAttr "unitConversion13.o" "polyTweak1.tk[4].tx";
connectAttr "unitConversion14.o" "polyTweak1.tk[4].ty";
connectAttr "unitConversion15.o" "polyTweak1.tk[4].tz";
connectAttr "unitConversion16.o" "polyTweak1.tk[5].tx";
connectAttr "unitConversion17.o" "polyTweak1.tk[5].ty";
connectAttr "unitConversion18.o" "polyTweak1.tk[5].tz";
connectAttr "unitConversion19.o" "polyTweak1.tk[6].tx";
connectAttr "unitConversion20.o" "polyTweak1.tk[6].ty";
connectAttr "unitConversion21.o" "polyTweak1.tk[6].tz";
connectAttr "unitConversion22.o" "polyTweak1.tk[7].tx";
connectAttr "unitConversion23.o" "polyTweak1.tk[7].ty";
connectAttr "unitConversion24.o" "polyTweak1.tk[7].tz";
connectAttr "unitConversion25.o" "polyTweak1.tk[8].tx";
connectAttr "unitConversion26.o" "polyTweak1.tk[8].ty";
connectAttr "unitConversion27.o" "polyTweak1.tk[8].tz";
connectAttr "unitConversion28.o" "polyTweak1.tk[9].tx";
connectAttr "unitConversion29.o" "polyTweak1.tk[9].ty";
connectAttr "unitConversion30.o" "polyTweak1.tk[9].tz";
connectAttr "unitConversion31.o" "polyTweak1.tk[10].tx";
connectAttr "unitConversion32.o" "polyTweak1.tk[10].ty";
connectAttr "unitConversion33.o" "polyTweak1.tk[10].tz";
connectAttr "unitConversion34.o" "polyTweak1.tk[11].tx";
connectAttr "unitConversion35.o" "polyTweak1.tk[11].ty";
connectAttr "unitConversion36.o" "polyTweak1.tk[11].tz";
connectAttr "unitConversion37.o" "polyTweak1.tk[12].tx";
connectAttr "unitConversion38.o" "polyTweak1.tk[12].ty";
connectAttr "unitConversion39.o" "polyTweak1.tk[12].tz";
connectAttr "unitConversion40.o" "polyTweak1.tk[13].tx";
connectAttr "unitConversion41.o" "polyTweak1.tk[13].ty";
connectAttr "unitConversion42.o" "polyTweak1.tk[13].tz";
connectAttr "unitConversion43.o" "polyTweak1.tk[14].tx";
connectAttr "unitConversion44.o" "polyTweak1.tk[14].ty";
connectAttr "unitConversion45.o" "polyTweak1.tk[14].tz";
connectAttr "unitConversion46.o" "polyTweak1.tk[15].tx";
connectAttr "unitConversion47.o" "polyTweak1.tk[15].ty";
connectAttr "unitConversion48.o" "polyTweak1.tk[15].tz";
connectAttr "unitConversion49.o" "polyTweak1.tk[16].tx";
connectAttr "unitConversion50.o" "polyTweak1.tk[16].ty";
connectAttr "unitConversion51.o" "polyTweak1.tk[16].tz";
connectAttr "unitConversion52.o" "polyTweak1.tk[17].tx";
connectAttr "unitConversion53.o" "polyTweak1.tk[17].ty";
connectAttr "unitConversion54.o" "polyTweak1.tk[17].tz";
connectAttr "unitConversion55.o" "polyTweak1.tk[18].tx";
connectAttr "unitConversion56.o" "polyTweak1.tk[18].ty";
connectAttr "unitConversion57.o" "polyTweak1.tk[18].tz";
connectAttr "unitConversion58.o" "polyTweak1.tk[19].tx";
connectAttr "unitConversion59.o" "polyTweak1.tk[19].ty";
connectAttr "unitConversion60.o" "polyTweak1.tk[19].tz";
connectAttr "pCubeShape2_pnts_0__pntx.o" "unitConversion1.i";
connectAttr "pCubeShape2_pnts_0__pnty.o" "unitConversion2.i";
connectAttr "pCubeShape2_pnts_0__pntz.o" "unitConversion3.i";
connectAttr "pCubeShape2_pnts_1__pntx.o" "unitConversion4.i";
connectAttr "pCubeShape2_pnts_1__pnty.o" "unitConversion5.i";
connectAttr "pCubeShape2_pnts_1__pntz.o" "unitConversion6.i";
connectAttr "pCubeShape2_pnts_2__pntx.o" "unitConversion7.i";
connectAttr "pCubeShape2_pnts_2__pnty.o" "unitConversion8.i";
connectAttr "pCubeShape2_pnts_2__pntz.o" "unitConversion9.i";
connectAttr "pCubeShape2_pnts_3__pntx.o" "unitConversion10.i";
connectAttr "pCubeShape2_pnts_3__pnty.o" "unitConversion11.i";
connectAttr "pCubeShape2_pnts_3__pntz.o" "unitConversion12.i";
connectAttr "pCubeShape2_pnts_4__pntx.o" "unitConversion13.i";
connectAttr "pCubeShape2_pnts_4__pnty.o" "unitConversion14.i";
connectAttr "pCubeShape2_pnts_4__pntz.o" "unitConversion15.i";
connectAttr "pCubeShape2_pnts_5__pntx.o" "unitConversion16.i";
connectAttr "pCubeShape2_pnts_5__pnty.o" "unitConversion17.i";
connectAttr "pCubeShape2_pnts_5__pntz.o" "unitConversion18.i";
connectAttr "pCubeShape2_pnts_6__pntx.o" "unitConversion19.i";
connectAttr "pCubeShape2_pnts_6__pnty.o" "unitConversion20.i";
connectAttr "pCubeShape2_pnts_6__pntz.o" "unitConversion21.i";
connectAttr "pCubeShape2_pnts_7__pntx.o" "unitConversion22.i";
connectAttr "pCubeShape2_pnts_7__pnty.o" "unitConversion23.i";
connectAttr "pCubeShape2_pnts_7__pntz.o" "unitConversion24.i";
connectAttr "pCubeShape2_pnts_8__pntx.o" "unitConversion25.i";
connectAttr "pCubeShape2_pnts_8__pnty.o" "unitConversion26.i";
connectAttr "pCubeShape2_pnts_8__pntz.o" "unitConversion27.i";
connectAttr "pCubeShape2_pnts_9__pntx.o" "unitConversion28.i";
connectAttr "pCubeShape2_pnts_9__pnty.o" "unitConversion29.i";
connectAttr "pCubeShape2_pnts_9__pntz.o" "unitConversion30.i";
connectAttr "pCubeShape2_pnts_10__pntx.o" "unitConversion31.i";
connectAttr "pCubeShape2_pnts_10__pnty.o" "unitConversion32.i";
connectAttr "pCubeShape2_pnts_10__pntz.o" "unitConversion33.i";
connectAttr "pCubeShape2_pnts_11__pntx.o" "unitConversion34.i";
connectAttr "pCubeShape2_pnts_11__pnty.o" "unitConversion35.i";
connectAttr "pCubeShape2_pnts_11__pntz.o" "unitConversion36.i";
connectAttr "pCubeShape2_pnts_12__pntx.o" "unitConversion37.i";
connectAttr "pCubeShape2_pnts_12__pnty.o" "unitConversion38.i";
connectAttr "pCubeShape2_pnts_12__pntz.o" "unitConversion39.i";
connectAttr "pCubeShape2_pnts_13__pntx.o" "unitConversion40.i";
connectAttr "pCubeShape2_pnts_13__pnty.o" "unitConversion41.i";
connectAttr "pCubeShape2_pnts_13__pntz.o" "unitConversion42.i";
connectAttr "pCubeShape2_pnts_14__pntx.o" "unitConversion43.i";
connectAttr "pCubeShape2_pnts_14__pnty.o" "unitConversion44.i";
connectAttr "pCubeShape2_pnts_14__pntz.o" "unitConversion45.i";
connectAttr "pCubeShape2_pnts_15__pntx.o" "unitConversion46.i";
connectAttr "pCubeShape2_pnts_15__pnty.o" "unitConversion47.i";
connectAttr "pCubeShape2_pnts_15__pntz.o" "unitConversion48.i";
connectAttr "pCubeShape2_pnts_16__pntx.o" "unitConversion49.i";
connectAttr "pCubeShape2_pnts_16__pnty.o" "unitConversion50.i";
connectAttr "pCubeShape2_pnts_16__pntz.o" "unitConversion51.i";
connectAttr "pCubeShape2_pnts_17__pntx.o" "unitConversion52.i";
connectAttr "pCubeShape2_pnts_17__pnty.o" "unitConversion53.i";
connectAttr "pCubeShape2_pnts_17__pntz.o" "unitConversion54.i";
connectAttr "pCubeShape2_pnts_18__pntx.o" "unitConversion55.i";
connectAttr "pCubeShape2_pnts_18__pnty.o" "unitConversion56.i";
connectAttr "pCubeShape2_pnts_18__pntz.o" "unitConversion57.i";
connectAttr "pCubeShape2_pnts_19__pntx.o" "unitConversion58.i";
connectAttr "pCubeShape2_pnts_19__pnty.o" "unitConversion59.i";
connectAttr "pCubeShape2_pnts_19__pntz.o" "unitConversion60.i";
connectAttr "polyMapSewMove21.out" "polyMapCut18.ip";
connectAttr "polyMapCut18.out" "polyTweakUV12.ip";
connectAttr "polyTweakUV12.out" "polyMapSewMove22.ip";
connectAttr "polyMapSewMove22.out" "polyMapCut19.ip";
connectAttr "polyMapCut19.out" "polyTweakUV13.ip";
connectAttr "polyTweakUV13.out" "polyMapSewMove23.ip";
connectAttr "polyMapSewMove23.out" "polyMapCut20.ip";
connectAttr "polyMapCut20.out" "polyMapSewMove24.ip";
connectAttr "polyMapSewMove24.out" "polyMapCut21.ip";
connectAttr "polyMapCut21.out" "polyTweakUV14.ip";
connectAttr "polyTweakUV11.out" "polyLayoutUV1.ip";
connectAttr "polyTweakUV14.out" "polyLayoutUV2.ip";
connectAttr "polyLayoutUV1.out" "polyTweakUV15.ip";
connectAttr "polyLayoutUV2.out" "polyTweakUV16.ip";
connectAttr "polyTweakUV15.out" "polyLayoutUV3.ip";
connectAttr "polyTweakUV16.out" "polyLayoutUV4.ip";
connectAttr "polyLayoutUV3.out" "polyTweakUV17.ip";
connectAttr "polyLayoutUV4.out" "polyTweakUV18.ip";
connectAttr "scrappySG.pa" ":renderPartition.st" -na;
connectAttr "gigbitSG.pa" ":renderPartition.st" -na;
connectAttr "lambert8.msg" ":defaultShaderList1.s" -na;
connectAttr "lambert4.msg" ":defaultShaderList1.s" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "pCubeShape1.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape2.iog" ":initialShadingGroup.dsm" -na;
// End of PressurePlate_Model.ma
