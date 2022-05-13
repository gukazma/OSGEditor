#pragma once
#include <qopenglwidget.h>
#include <memory>
#include <Function/Event/Input.h>

#include <osgViewer/GraphicsWindow>
#include <osgViewer/Viewer>
namespace Soarscape
{
	class EditorRendererWidget : public QOpenGLWidget
	{
	public:
		EditorRendererWidget(QWidget* parent);
		~EditorRendererWidget();
		
		void initializeGL() override;
		void resizeGL(int w, int h) override;
		void paintGL() override;
		// Event handlers
		virtual void mousePressEvent(QMouseEvent* event) override;
		virtual void mouseReleaseEvent(QMouseEvent* event) override;
		virtual void mouseDoubleClickEvent(QMouseEvent* event) override;
		virtual void mouseMoveEvent(QMouseEvent* event) override;
		virtual void wheelEvent(QWheelEvent* event) override;


		std::shared_ptr<MousePos> m_MousePos;
		std::shared_ptr<MouseAngle> m_MouseAngle;

		void importMesh(const std::string filename);
	private:
		void renderImGui();
        /*osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> m_GraphicsWindow;
        osg::ref_ptr<osgViewer::Viewer> m_Viewer;

		bool m_isFirstFrame = true;*/
	};
}