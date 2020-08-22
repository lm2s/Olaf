// Olaf: Overly Lightweight Acoustic Fingerprinting
// Copyright (C) 2019-2020  Joren Six

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

const float gaussian_window[] = {
   0.043937,
   0.045023,
   0.046131,
   0.047262,
   0.048416,
   0.049594,
   0.050795,
   0.052021,
   0.053271,
   0.054545,
   0.055845,
   0.057171,
   0.058522,
   0.059900,
   0.061304,
   0.062735,
   0.064193,
   0.065679,
   0.067192,
   0.068734,
   0.070305,
   0.071905,
   0.073534,
   0.075193,
   0.076882,
   0.078601,
   0.080351,
   0.082132,
   0.083945,
   0.085789,
   0.087665,
   0.089574,
   0.091516,
   0.093491,
   0.095499,
   0.097542,
   0.099618,
   0.101729,
   0.103874,
   0.106055,
   0.108271,
   0.110523,
   0.112810,
   0.115135,
   0.117495,
   0.119893,
   0.122328,
   0.124800,
   0.127311,
   0.129859,
   0.132445,
   0.135071,
   0.137735,
   0.140438,
   0.143180,
   0.145962,
   0.148784,
   0.151646,
   0.154548,
   0.157491,
   0.160474,
   0.163498,
   0.166563,
   0.169670,
   0.172817,
   0.176007,
   0.179238,
   0.182511,
   0.185825,
   0.189182,
   0.192581,
   0.196023,
   0.199507,
   0.203033,
   0.206602,
   0.210213,
   0.213867,
   0.217564,
   0.221303,
   0.225086,
   0.228910,
   0.232778,
   0.236688,
   0.240641,
   0.244637,
   0.248675,
   0.252756,
   0.256879,
   0.261044,
   0.265251,
   0.269500,
   0.273791,
   0.278124,
   0.282499,
   0.286914,
   0.291371,
   0.295869,
   0.300408,
   0.304986,
   0.309605,
   0.314264,
   0.318963,
   0.323700,
   0.328477,
   0.333292,
   0.338145,
   0.343037,
   0.347965,
   0.352931,
   0.357933,
   0.362971,
   0.368046,
   0.373155,
   0.378299,
   0.383477,
   0.388689,
   0.393934,
   0.399211,
   0.404521,
   0.409862,
   0.415233,
   0.420635,
   0.426066,
   0.431526,
   0.437014,
   0.442530,
   0.448072,
   0.453641,
   0.459234,
   0.464852,
   0.470494,
   0.476158,
   0.481845,
   0.487553,
   0.493281,
   0.499029,
   0.504795,
   0.510579,
   0.516380,
   0.522197,
   0.528029,
   0.533874,
   0.539733,
   0.545604,
   0.551486,
   0.557378,
   0.563279,
   0.569188,
   0.575104,
   0.581026,
   0.586953,
   0.592883,
   0.598816,
   0.604750,
   0.610685,
   0.616619,
   0.622551,
   0.628480,
   0.634404,
   0.640323,
   0.646236,
   0.652140,
   0.658036,
   0.663921,
   0.669795,
   0.675656,
   0.681503,
   0.687335,
   0.693150,
   0.698948,
   0.704726,
   0.710485,
   0.716222,
   0.721936,
   0.727626,
   0.733291,
   0.738929,
   0.744539,
   0.750120,
   0.755670,
   0.761189,
   0.766674,
   0.772125,
   0.777541,
   0.782919,
   0.788259,
   0.793560,
   0.798819,
   0.804037,
   0.809211,
   0.814341,
   0.819424,
   0.824461,
   0.829449,
   0.834387,
   0.839274,
   0.844109,
   0.848891,
   0.853618,
   0.858289,
   0.862903,
   0.867459,
   0.871955,
   0.876391,
   0.880765,
   0.885076,
   0.889323,
   0.893505,
   0.897621,
   0.901669,
   0.905649,
   0.909559,
   0.913399,
   0.917167,
   0.920862,
   0.924484,
   0.928031,
   0.931503,
   0.934898,
   0.938216,
   0.941455,
   0.944615,
   0.947695,
   0.950694,
   0.953611,
   0.956445,
   0.959196,
   0.961863,
   0.964445,
   0.966942,
   0.969352,
   0.971675,
   0.973910,
   0.976057,
   0.978115,
   0.980083,
   0.981962,
   0.983750,
   0.985447,
   0.987052,
   0.988565,
   0.989986,
   0.991314,
   0.992548,
   0.993689,
   0.994736,
   0.995689,
   0.996547,
   0.997311,
   0.997980,
   0.998553,
   0.999031,
   0.999414,
   0.999701,
   0.999892,
   0.999988,
   0.999988,
   0.999892,
   0.999701,
   0.999414,
   0.999031,
   0.998553,
   0.997980,
   0.997311,
   0.996547,
   0.995689,
   0.994736,
   0.993689,
   0.992548,
   0.991314,
   0.989986,
   0.988565,
   0.987052,
   0.985447,
   0.983750,
   0.981962,
   0.980083,
   0.978115,
   0.976057,
   0.973910,
   0.971675,
   0.969352,
   0.966942,
   0.964445,
   0.961863,
   0.959196,
   0.956445,
   0.953611,
   0.950694,
   0.947695,
   0.944615,
   0.941455,
   0.938216,
   0.934898,
   0.931503,
   0.928031,
   0.924484,
   0.920862,
   0.917167,
   0.913399,
   0.909559,
   0.905649,
   0.901669,
   0.897621,
   0.893505,
   0.889323,
   0.885076,
   0.880765,
   0.876391,
   0.871955,
   0.867459,
   0.862903,
   0.858289,
   0.853618,
   0.848891,
   0.844109,
   0.839274,
   0.834387,
   0.829449,
   0.824461,
   0.819424,
   0.814341,
   0.809211,
   0.804037,
   0.798819,
   0.793560,
   0.788259,
   0.782919,
   0.777541,
   0.772125,
   0.766674,
   0.761189,
   0.755670,
   0.750120,
   0.744539,
   0.738929,
   0.733291,
   0.727626,
   0.721936,
   0.716222,
   0.710485,
   0.704726,
   0.698948,
   0.693150,
   0.687335,
   0.681503,
   0.675656,
   0.669795,
   0.663921,
   0.658036,
   0.652140,
   0.646236,
   0.640323,
   0.634404,
   0.628480,
   0.622551,
   0.616619,
   0.610685,
   0.604750,
   0.598816,
   0.592883,
   0.586953,
   0.581026,
   0.575104,
   0.569188,
   0.563279,
   0.557378,
   0.551486,
   0.545604,
   0.539733,
   0.533874,
   0.528029,
   0.522197,
   0.516380,
   0.510579,
   0.504795,
   0.499029,
   0.493281,
   0.487553,
   0.481845,
   0.476158,
   0.470494,
   0.464852,
   0.459234,
   0.453641,
   0.448072,
   0.442530,
   0.437014,
   0.431526,
   0.426066,
   0.420635,
   0.415233,
   0.409862,
   0.404521,
   0.399211,
   0.393934,
   0.388689,
   0.383477,
   0.378299,
   0.373155,
   0.368046,
   0.362971,
   0.357933,
   0.352931,
   0.347965,
   0.343037,
   0.338145,
   0.333292,
   0.328477,
   0.323700,
   0.318963,
   0.314264,
   0.309605,
   0.304986,
   0.300408,
   0.295869,
   0.291371,
   0.286914,
   0.282499,
   0.278124,
   0.273791,
   0.269500,
   0.265251,
   0.261044,
   0.256879,
   0.252756,
   0.248675,
   0.244637,
   0.240641,
   0.236688,
   0.232778,
   0.228910,
   0.225086,
   0.221303,
   0.217564,
   0.213867,
   0.210213,
   0.206602,
   0.203033,
   0.199507,
   0.196023,
   0.192581,
   0.189182,
   0.185825,
   0.182511,
   0.179238,
   0.176007,
   0.172817,
   0.169670,
   0.166563,
   0.163498,
   0.160474,
   0.157491,
   0.154548,
   0.151646,
   0.148784,
   0.145962,
   0.143180,
   0.140438,
   0.137735,
   0.135071,
   0.132445,
   0.129859,
   0.127311,
   0.124800,
   0.122328,
   0.119893,
   0.117495,
   0.115135,
   0.112810,
   0.110523,
   0.108271,
   0.106055,
   0.103874,
   0.101729,
   0.099618,
   0.097542,
   0.095499,
   0.093491,
   0.091516,
   0.089574,
   0.087665,
   0.085789,
   0.083945,
   0.082132,
   0.080351,
   0.078601,
   0.076882,
   0.075193,
   0.073534,
   0.071905,
   0.070305,
   0.068734,
   0.067192,
   0.065679,
   0.064193,
   0.062735,
   0.061304,
   0.059900,
   0.058522,
   0.057171,
   0.055845,
   0.054545,
   0.053271,
   0.052021,
   0.050795,
   0.049594,
   0.048416,
   0.047262,
   0.046131,
   0.045023,
   0.043937,
};