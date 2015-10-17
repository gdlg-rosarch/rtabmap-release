/*
Copyright (c) 2010-2014, Mathieu Labbe - IntRoLab - Universite de Sherbrooke
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Universite de Sherbrooke nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef EXPORTCLOUDSDIALOG_H_
#define EXPORTCLOUDSDIALOG_H_

#include <QDialog>
#include <QtCore/QSettings>

class Ui_ExportCloudsDialog;
class QAbstractButton;

namespace rtabmap {

class ExportCloudsDialog : public QDialog
{
	Q_OBJECT

public:
	ExportCloudsDialog(QWidget *parent = 0);

	virtual ~ExportCloudsDialog();

	void saveSettings(QSettings & settings, const QString & group = "") const;
	void loadSettings(QSettings & settings, const QString & group = "");

	void setSaveButton();
	void setOkButton();
	void enableRegeneration(bool enabled);

	//getters
	bool getBinaryFile() const;
	int getNormalKSearch() const;

	bool getGenerate() const;
	int getGenerateDecimation() const;
	double getGenerateVoxel() const;
	double getGenerateMaxDepth() const;

	bool getFiltering() const;
	double getFilteringRadius() const;
	int getFilteringMinNeighbors() const;

	bool getAssemble() const;
	double getAssembleVoxel() const;

	bool getMLS() const;
	double getMLSRadius() const;
	int getMLSPolygonialOrder() const;
	int getMLSUpsamplingMethod() const;
	double getMLSUpsamplingRadius() const;
	double getMLSUpsamplingStep() const;
	int getMLSPointDensity() const;
	double getMLSDilationVoxelSize() const;
	int getMLSDilationIterations() const;

	bool getMesh() const;
	double getMeshGp3Radius() const;
	double getMeshGp3Mu() const;
	double getMeshDecimationFactor() const;
	bool getMeshTexture() const;

signals:
	void configChanged();

public slots:
	void restoreDefaults();

private slots:
	void updateMLSGrpVisibility();

private:
	Ui_ExportCloudsDialog * _ui;
};

}

#endif /* EXPORTCLOUDSDIALOG_H_ */
